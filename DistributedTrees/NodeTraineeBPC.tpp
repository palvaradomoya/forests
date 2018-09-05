/*
 * File:   NodeTraineeBPC.cpp
 * Author: Sygram
 *
 */

#include "NodeTraineeBPC.h"

using namespace rdf::bpc;


template <typename T>
NodeTrainee<T>::NodeTrainee() {
}

template <typename T>
NodeTrainee<T>::NodeTrainee(const NodeTrainee& orig) {
}

template <typename T>
int NodeTrainee<T>::GetLevel() {
  int id = nodeId_;
  int count = 1;
  while ( (id >>= 1) > 0) count++;
  return count;
}

template <typename T>
NodeTrainee<T>::~NodeTrainee() {
}
