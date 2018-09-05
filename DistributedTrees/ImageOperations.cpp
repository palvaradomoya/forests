/*
 * File:   ImageOperations.cpp
 * Author: Sygram
 *
 * 
 */

#include "ImageOperations.h"

using namespace rdf;

ImageOperations::ImageOperations() {
}

ImageOperations::ImageOperations(const ImageOperations& orig) {
}


void ImageOperations::SetImagesDistribution(
  std::vector<Estructura::Node>& imagesSet,
  int percentage,
  int numTrees
){
    int total = imagesSet.size();
    int percentageNum = (percentage / 100) * total;
    for (int i = 0; i < numTrees; i++) {
      AssignTreeFlagsToImagesSet(imagesSet, percentageNum, i, total);
    }
}

void ImageOperations::AssignTreeFlagsToImagesSet(
  std::vector<Estructura::Node>& imagesSet,
  int percentageNum,
  int treeNum,
  int totalSize
){
    int count = 0;
    int randomNum = 0;
    int treeFlag = 0;
    std::uniform_int_distribution<int> int_dist(0, totalSize - 1);
    while (count < percentageNum) {
      randomNum = int_dist(mt_);
      treeFlag = imagesSet[randomNum].treesAvailability[treeNum];
      if (treeFlag == 0){
        imagesSet[randomNum].treesAvailability[treeNum] = 1;
        count++;
      }
    }
  }





ImageOperations::~ImageOperations() {
}



std::mt19937 ImageOperations::InitRandomSeed() {
    std::random_device rd;
    std::mt19937 mt(rd());
    return mt;
}

std::mt19937 ImageOperations::mt_ = ImageOperations::InitRandomSeed();
