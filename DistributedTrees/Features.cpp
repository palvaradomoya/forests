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
  x1 = feat1_x;
  y1 = feat2_y;
  x2 = feat1_y;
  y2 = feat2_x;
}

Features::Features(const Features& orig) {
  x1 = orig.x1;
  y1 = orig.y1;
  x2 = orig.x2;
  y2 = orig.y2;
}

Feature Features::SetFeature1(float x, float y){
    x1 = x;
    y1 = y;
  return feature1_;
}

Feature Features::SetFeature2(float x, float y){
  x2 = x;
  y2 = y;
  return feature2_;
}

float Features::GetFeature1X(){
  return x1;
}
float Features::GetFeature1Y(){
  return y1;
}

float Features::GetFeature2X(){
  return x2;
}
float Features::GetFeature2Y(){
  return y2;
}

Features::~Features() {
}
