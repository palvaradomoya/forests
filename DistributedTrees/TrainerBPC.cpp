/*
 * File:   TrainerBPC.cpp
 * Author: Sygram
 *
 */

#include "TrainerBPC.h"
#include <iostream>

using namespace rdf::bpc;

Trainer::Trainer() {

}

Trainer::Trainer(const Trainer& orig) {
}


void Trainer::Train(Node * node, std::vector<Estructura::Node>& imagesTrainingSet, rdf::NodeResult& nodeResult){
  std::cout<< "Trainning...\n";
  NodeTrainee<Cell>* nodeTrainee = static_cast<NodeTrainee<Cell>* > (node);
  int nodeId =  nodeTrainee->nodeId_;
  int treeId =  nodeTrainee->treeId_;
  int nodeInTree, pointsSize, treeFlag;
  std::vector<Estructura::Pixel> *points = nullptr;
  std::cout << "nodeId: "<< nodeId << "\ttreeId: "<< treeId << '\n';
  int n = 0;
  for (auto &image : imagesTrainingSet) { // for every image
    // treeFlag = image.treesAvailability[treeId];
     if (treeFlag == 0) continue; //this means image doesn't belong to given tree
      points = &image.points;
      for (auto const &point : *points) {           // for every point
        // std::cout << "gg!" << ++n << '\n';
            nodeInTree = point.ubicacion[treeId];
            cv::Point p = point.point;

            /*if (nodeInTree == nodeId){
               // nodeTrainee->GetMatrix().EvaluatePointInMatrix(point); //for every feature and threshold
            }*/
          //std::cout << "Punto ("<< p.x << "," << p.y <<") \n";
        }
  }
//  nodeTrainee->GetMatrix().Print();
   nodeResult.setMatrixResults(nodeTrainee->GetMatrix());
  //nodeResult.getMatrixResults().Print();

}

Trainer::~Trainer() {
}
