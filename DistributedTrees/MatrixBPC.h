/*
 * File:   MatrixBPC.h
 * Author: Sygram
 *
 * Class: rdf::bpc::Matrix
 * Needs revision: Yes. Real calculations must be implemented in place of
 * proof of concept ones.
 * Status: Working.
 * Description: This class contains all the matrix/data information that each
 * node must contain during training. It contains 2 matrices, one for random
 * features and thresholds and another one for saving left and right cells
 * histograms.
 *
 */

#ifndef MATRIXBPC_H
#define MATRIXBPC_H

#include "Matrix.h"
#include "FeaturesMat.h"
#include <stdlib.h>
#include <omp.h>
#include "CellBPC.h"

#include <boost/serialization/split_member.hpp>


namespace rdf {
  namespace bpc {

    //TODO - Work on better structure/interface for this class

    template <typename T>
    class Matrix: public rdf::Matrix<T> {
    public:
         Matrix();
         Matrix(const FeaturesMat &);
         Matrix(const Matrix& orig);
        virtual ~Matrix();
        void AddFeaturesMat(const FeaturesMat &mat);
         void AllocateCells();
      //    void train();
         void Reduce(Matrix &other);
         void Average(int average);
         void Print();
         void EvaluatePointInMatrix(int point);
         float CalculateFeatureResponse(int, int, int);
         bool EvaluateFeatureResponseForThreshold(float, int);
         T operator ()(int i, int j){
             return cells_[i * this->rows_ + j];
         }
        std::pair<int,int> FindBestPair(){
           return std::make_pair(2,3);
         }

         /* Data members */

         FeaturesMat featuresMatrix_;

    private:
               int rows_;
               int cols_;
               T* cells_;

            friend class boost::serialization::access;

   template<class Archive>
   void save(Archive & ar, const unsigned int version) const
   {
     ar & featuresMatrix_;
     ar & rows_;
     ar & cols_;
     for (size_t i = 0; i < rows_; i++) {
       for (size_t j = 0; j < cols_; j++) {
         ar & cells_[i * rows_ + j];
       }
     }
   }
   template<class Archive>
      void load(Archive & ar, const unsigned int version)
      {
        ar & featuresMatrix_;
        ar & rows_;
        ar & cols_;
        AllocateCells();
        for (size_t i = 0; i < rows_; i++) {
          for (size_t j = 0; j < cols_; j++) {
            ar & cells_[i * rows_ + j];
          }
        }
      }

      BOOST_SERIALIZATION_SPLIT_MEMBER()

    };

  } /* bpc */
} /* rdf */


#include "MatrixBPC.tpp"

#endif /* MATRIXBPC_H */
