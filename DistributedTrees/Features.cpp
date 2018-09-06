/*
 * File:   Features.cpp
 * Author: Sygram
 *
 */

#include "Features.h"


using namespace rdf::bpc;

Features::Features() {
  feature1_.x = 0;
  feature1_.y = 0;
  feature2_.x = 0;
  feature2_.y = 0;
}

Features::Features(float feat1_x, float feat1_y, float feat2_x, float feat2_y) {
  feature1_.x = feat1_x;
  feature1_.y = feat1_y;
  feature2_.x = feat2_x;
  feature2_.y = feat2_y;
}

Features::Features(const Features& orig) {
  // feature1_ = orig.feature1_;
  // feature2_ = orig.feature2_;
  this->feature1_.x = orig.feature1_.x;
  this->feature1_.y = orig.feature1_.y;
  this->feature2_.x = orig.feature2_.x;
  this->feature2_.y = orig.feature2_.y;
}

Feature Features::SetFeature1(float x, float y){
  feature1_.x = x;
  feature1_.y = y;
  return feature1_;
}

Feature Features::SetFeature2(float x, float y){
  feature2_.x = x;
  feature2_.y = y;
  return feature2_;
}

Feature Features::GetFeature1(){
  return feature1_;
}

Feature Features::GetFeature2(){
  return feature2_;
}


Features::~Features() {
}
