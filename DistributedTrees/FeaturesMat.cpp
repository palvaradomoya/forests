/*
 * File:   FeaturesMat.cpp
 * Author: Sygram
 *
 */

#include "FeaturesMat.h"

using namespace rdf::bpc;
using namespace std;



FeaturesMat::FeaturesMat() {
  thresholdsLowRange_ = 0;
  thresholdsHighRange_ = 0;
  featuresLowRange_ = 0;
  featuresHighRange_ = 0;
  numFeatures_ = 0;
  numThresholds_ = 0;
}

FeaturesMat::FeaturesMat(int numFeatures, float featuresHigh,
        float featuresLow, int numThresholds, float thresholdsHigh, float thresholdsLow) {

    SetMatrixSize(numFeatures, numThresholds);
    SetThresholdsNumRange(thresholdsHigh,thresholdsLow);
    SetFeaturesNumRange(featuresHigh, featuresLow);
}

FeaturesMat::FeaturesMat(const FeaturesMat& orig) {
  SetMatrixSize( orig.numFeatures_, orig.numThresholds_);
  thresholds_ =  orig.thresholds_;
  features_=  orig.features_;
}

FeaturesMat::~FeaturesMat() {

}

void FeaturesMat::SetMatrixSize(int x, int y) {
    numFeatures_ = x; //Matrix ROWS
    numThresholds_ = y; //Matrix COLS
    features_.resize(x);
    thresholds_.resize(y);
}

void FeaturesMat::SetNumThresholds(int n) {
    numThresholds_ = n;
    thresholds_.resize(n);
}

void FeaturesMat::SetNumFeatures(int n) {
    numFeatures_ = n;
    features_.resize(n);
}

void FeaturesMat::SetThresholdsNumRange(float low, float high) {
    thresholdsLowRange_ = low;
    thresholdsHighRange_ = high;
}

void FeaturesMat::SetFeaturesNumRange(float low, float high) {
    featuresLowRange_ = low;
    featuresHighRange_ = high;
}

void FeaturesMat::GenerateThresholdsVector() {
    float randomThreshold;
    std::uniform_real_distribution<float> threshold_dist(thresholdsLowRange_, thresholdsHighRange_);
    for (size_t i = 0; i < numThresholds_; i++) {
        randomThreshold = threshold_dist(mt_);
        thresholds_[i] = randomThreshold;
    }
}

void FeaturesMat::GenerateFeaturesVector() {
    float randomFeature1X, randomFeature1Y, randomFeature2X, randomFeature2Y;
    Features myFeature;
    std::uniform_real_distribution<float> features_dist(featuresLowRange_, featuresHighRange_);
    for (size_t i = 0; i < numFeatures_; i++) {
        randomFeature1X = features_dist(mt_);
        randomFeature1Y = features_dist(mt_);
        randomFeature2X = features_dist(mt_);
        randomFeature2Y = features_dist(mt_);
        myFeature.SetFeature1(randomFeature1X, randomFeature1Y);
        myFeature.SetFeature2(randomFeature2X, randomFeature2Y);
        features_[i] = myFeature;
    }
}

void FeaturesMat::GenerateVectors() {
    GenerateThresholdsVector();
    GenerateFeaturesVector();
}

void FeaturesMat::Print() {
    float randomThreshold, randomFeature1X, randomFeature1Y, randomFeature2X, randomFeature2Y;
    Features feat;
    for (size_t i = 0; i < numFeatures_; i++) {
        feat = features_[i];
        randomFeature1X = feat.GetFeature1().x;
        randomFeature1Y = feat.GetFeature1().y;
        randomFeature2X = feat.GetFeature2().x;
        randomFeature2Y = feat.GetFeature2().y;
        for (size_t j = 0; j < numThresholds_; j++) {
            randomThreshold = thresholds_[j];
            cout << "[" << i << "][" << j << "]: T=" << randomThreshold
                    << "\tF1X=" << randomFeature1X << "\tF1Y=" << randomFeature1Y
                    << "\tF2X=" << randomFeature2X << "\tF2Y=" << randomFeature2Y << "\n";
        }
    }
}



std::mt19937 InitializeRandomDevice() {
    std::random_device rd;
    std::mt19937 mt(rd());
    return mt;
}

std::mt19937 FeaturesMat::mt_ = InitializeRandomDevice();
