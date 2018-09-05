/*
 * File:   NodeTraineeBPC.h
 * Author: Sygram
 *
 * Class: rdf::bpc::NodeTraineeBPC<T>
 * Needs revision: Probably. Needs further advancement in project.
 * Description: Concrete class. This class is the implementation of
 * NodeTrainee and Node classes.
 * Contains the required matrix for the shotton algorithm implementation.
 * It also has basic node operations.
 *
 */

#ifndef NODETRAINEEBPC_H
#define NODETRAINEEBPC_H

#include "MatrixBPC.h"
#include "NodeTrainee.h"

namespace rdf {

  namespace bpc {

    template <typename T>
    class NodeTrainee : public rdf::NodeTrainee {
    public:
      NodeTrainee();
      NodeTrainee(const NodeTrainee& orig);
      inline Matrix<T>& GetMatrix(){ return this->matrix_; };
      virtual ~NodeTrainee();
      Node * GetLeft(){};
      Node * GetRight(){};
      inline int GetParentId(){ return nodeId_ >> 1; }
      int GetLevel();
      inline void SetTreeId(int id){
        treeId_ = id;
      }
      inline void SetNodeId(int id){
        nodeId_ = id;
      }
      inline Matrix<T> GetNodeMatrix(){
        return matrix_;
      }
      /* Data members */
      int nodeId_;
      int treeId_;

    private:

      /* Data members */
      Matrix<T> matrix_;


    };

  } /* bpc */

} /* rdf */


#include "NodeTraineeBPC.tpp"

#endif /* NODETRAINEEBPC_H */
