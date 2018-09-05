/*
 * File:   NodeTrainee.h
 * Author: Sygram
 *
 * Class: rdf::NodeTrainee
 * Needs revision: Maybe. Consult with coordinator.
 * Description: Derived class. Abstract class meant to be used as a reference for Training Nodes.
 * All Training Nodes implementation classes from all algorithms must inherit
 * from this class. Base class Node.
 */

#ifndef NODETRAINEE_H
#define NODETRAINEE_H

#include "Node.h"

namespace rdf {

  class NodeTrainee : public rdf::Node {
  public:
    NodeTrainee();
    NodeTrainee(const NodeTrainee& orig);
    // virtual void train() = 0;
    virtual ~NodeTrainee();
  private:

  };

} /* rdf */


#endif /* NODETRAINEE_H */
