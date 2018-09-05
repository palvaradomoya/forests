/*
 * File:   ImageManager.cpp
 * Author: Will
 *
 */

#include "ImageManager.h"

namespace rdf {

  ImageManager::ImageManager() {
    dataMaster.NumPoints = 15;
    dataMaster.height = 240;
    dataMaster.width = 320;
    dataMaster.NumTree = 3;
    dataMaster.tree = 0;
    dataMaster.node = 0;
    dataMaster.type_Algorithm = "shotton";
  }

  ImageManager::ImageManager(const ImageManager& orig) {
  }

  ImageManager::~ImageManager() {
  }

  void ImageManager::setRange(std::pair<int, int> pRange) {
    dataMaster.startRead = pRange.first;
    dataMaster.endRead = pRange.second;
  }

  void ImageManager::loadImages() {
    image.getStructura(structure, dataMaster);

  }

  //! This function either shows the image in a frame or prints the
  //! points in the pixels vector.
  void ImageManager::showStructure(bool showImages) {
    //desmostracion de la estructura esta bien
    for (int i = 0; i < structure.size(); i++) {
      img = structure[i].imageLabel;
      std::vector<Estructura::Pixel> pixel = structure[i].points;
      if(showImages){
        estructura.seeImageLabel(img);
        estructura.seeImageDepth(240,320,img);
      }
      else {
        for (int j = 0; j < pixel.size(); j++) {
          std::cout <<  pixel[j].point << "\n";
        }
      }
    }
  }

} /* rdf */
