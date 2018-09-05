/*
 * File:   Matrix.h
 * Author: Sygram
 *
 * Class: rdf::Matrix
 * Needs revision: Yes. Implement coordinator Matrix version.
 * Possible improvements: Implement as a library.
 * Description: This class contains a basic Matrix class implementation.
 * Designed for general use within the project.
 */

#ifndef MATRIX_H
#define MATRIX_H

#include "Cell.h"

namespace rdf {

  template <typename T>
  class Matrix {
  public:
    Matrix();
    Matrix(const Matrix& orig);
   // virtual void Reduce(Matrix &other) = 0;
    virtual ~Matrix();
  private:
    // T cl

  };

} /* rdf */

#include "Matrix.tpp"

#endif /* MATRIX_H */
