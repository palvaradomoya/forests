/*
 * File:   Task.cpp
 * Author: gabo
 *
 */

#include "Task.h"

rdf::Task::Task() {
    _featureMatrix.SetMatrixSize(VECTOR_AMOUNT,THRESHOLD_AMOUNT);
    _featureMatrix.SetThresholdsNumRange(100,0);
    _featureMatrix.SetFeaturesNumRange(100,0);
    _featureMatrix.GenerateVectors();
    //_featureMatrix.Print();
}

rdf::Task::Task(const Task& orig) {
    _rank           = orig._rank;
    _tree           = orig._tree;
    _node           = orig._node;
    _status         = orig._status;
    _featureMatrix  = orig._featureMatrix;
}


rdf::Task::~Task() {

}

rdf::Task::Task( int _rank,  int _tree,  int _node, bool _status) {
    _rank = _rank;
    _tree = _tree;
    _node = _node;
    _status = _status;
}

void rdf::Task::showTask() {
    std::cout << "{ " <<_rank <<  "," << _tree << "," << _node <<"," <<_status << " } \n";
}

void rdf::Task::reduce(Task& pTask) {
    _rank   = _rank + pTask.getRank();
    _tree   = _tree + pTask.getTree();
    _node   = _node + pTask.getNode();
    _status = pTask.isStatus();
}
