/*
 * File:   CellBPC.h
 * Author: Sygram
 *
 * Class: rdf::bpc::Cell
 * Needs revision: Minimal
 * Description: This class holds the Shotton Algorithm cell/node histogram. It
 * contains left/right histograms, as well as some useful functions for
 * processing the data they hold.
  */

#ifndef CELLBPC_H
#define CELLBPC_H

#define BODY_PARTS_NUM 2

#include "Cell.h"

#include <vector>
#include <string>
#include <iostream>

// include headers that implement a archive in simple text format
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include <boost/serialization/vector.hpp>



namespace rdf{

  namespace bpc {

    class Cell : public rdf::Cell{
    public:
      Cell();
      Cell(const Cell& orig);
      std::vector<float> left;      ///< Left histogram
      std::vector<float> right;     ///< Right histogram
      // Cell& Reduce(const Cell& other);
      void Reduce(const Cell& other);
      void SumByIndex(int toLeft, int index, float val);
      void SumByBodyPart(int toLeft, std::string bodyPart, float val);
      void InitValues(float leftVals, float rightVals);
      void AverageValues(int num);
      void Print();
      virtual ~Cell();
    private:
          /* --- Serialization --- */
          friend class boost::serialization::access;
          template<class Archive>
          void serialize(Archive & ar, const unsigned int version)
          {
            ar & left;
            ar & right;
          }
          /* ==== Serialization ==== */
      void Print(int i);
      int BodyPartToIndex(std::string bodyPart);

    };
  } /* bpc */
} /* rdf */

#endif /* CELLBPC_H */
