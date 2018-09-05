 /*
 * File:   CellBPC.cpp
 * Author: Sygram
 *
 */

 #include "CellBPC.h"

namespace rdf {
  namespace bpc {

    Cell::Cell() {
      left.resize(BODY_PARTS_NUM, 8.0);
      right.resize(BODY_PARTS_NUM, 1.0);
    }

    Cell::Cell(const Cell& orig) {
      left = orig.left;
      right = orig.right;
    }

    void Cell::Reduce(const Cell& other) {
      float otherLeft, otherRight;
      for (int i = 0; i < BODY_PARTS_NUM; i++) {
        otherLeft = other.left[i];
        otherRight = other.right[i];
        left[i] = left[i] + otherLeft;
        right[i] = right[i] + otherRight;
      }
    }

    void Cell::InitValues(float leftValues, float rightValues){
      for (int i = 0; i < BODY_PARTS_NUM; i++) {
        left[i] = leftValues;
        right[i] = rightValues;
      }
    }

    void Cell::SumByIndex(int toLeft, int index, float value){
      (toLeft) ? left[index] += value : right[index] += value;
    }

    void Cell::SumByBodyPart(int toLeft, std::string bodyPart, float val){
      int index = BodyPartToIndex(bodyPart);
      SumByIndex(toLeft, index, val);

    }

    void Cell::AverageValues(int num){
      for (int i = 0; i < BODY_PARTS_NUM; i++) {
        left[i] = left[i] / num;
        right[i] = right[i] / num;
      }
    }

    //TODO - FINISH
    int Cell::BodyPartToIndex(std::string bodyPart){
      if (bodyPart == "brazo"){
        return 0;
      }
      else if (bodyPart == "dedo"){
        return 1;
      }
      else if (bodyPart == "mano"){
        return 2;
      }
      else if (bodyPart == "cabeza"){
        return 3;
      }
      else if (bodyPart == "pecho"){
        return 4;
      }

      /* etc..... */
    }


    void Cell::Print(){
      for (int i = 0; i < BODY_PARTS_NUM; i++) {
        std::cout << "Left: " << left[i] << "\tRight: " << right[i] << std::endl;
      }
    }

    void Cell::Print(int i){
        std::cout << "i[" << i << "]" <<"Left: " << left[i] << "\tRight: " << right[i] << std::endl;
    }

    Cell::~Cell() {

    }
  } /* bpc */
} /* rdf */
