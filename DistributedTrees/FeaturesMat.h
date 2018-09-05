/*
 * File:   FeaturesMat.h
 * Author: Sygram
 *
 *
 */

#ifndef FEATURESMAT_H
#define FEATURESMAT_H

#include <vector>
#include <utility>
#include <random>
#include <assert.h>
#include <iostream>

#include <fstream>

// include headers that implement a archive in simple text format
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include <boost/serialization/vector.hpp>

#include "Features.h"



namespace rdf {
  namespace bpc {

    template <class T>
    class Matrix;

    class FeaturesMat {
    public:
      //! Default constructor. Initializes to 0.
      FeaturesMat();

      //! Copy constructor.
      FeaturesMat(const FeaturesMat& orig);

      //! Constructor. Complete. This constructor sets all the required
      //! parameters needed to initialize the class fully.
      FeaturesMat(int fn, float fh, float fl, int tn, float th, float tl);

      //! Sets the size of the matrix.
      //! \param x is the number of Features
      //! \param y is the number of Thresholds
      void SetMatrixSize(int x, int y);


      //! Sets the number of thresholds
      void SetNumThresholds(int);

      //! Sets the number of features
      void SetNumFeatures(int);

      //! Sets the floating point range of the random thresholds.
      //! \param low for the minimun threshold value.
      //! \param high for the maximun threshold value.
      void SetThresholdsNumRange(float low, float high);

      //! Sets the floating point range of the random features.
      //! \param low for the minimun threshold value.
      //! \param high for the maximun threshold value.
      void SetFeaturesNumRange(float low, float high);

      //! This function generates the random vectors for thresholds and features.
      //! \sa GenerateThresholdsVector(), GenerateFeaturesVector()
      void GenerateVectors();

      //! Returns the floating point threshold value at given position.
      //! \param x position of threshold.
      //! \return The threshold at position x.
      inline float GetThresholdAt(int x){
        return thresholds_[x];
      }

      //! Returns the feature at given position.
      //! \param x position of feature.
      //! \return The feature at position x.
      inline Features GetFeaturesAt(int x){
        return features_[x];
      }

      //! This function prints the floating point values of the features matrix.
      //! Including both Thresholds and Features.
      void Print();

      //! Destructor.
      virtual ~FeaturesMat();


    private:
      //!<  TODO: Justify friendship
      template <class T> friend class Matrix;

      //!< Friend class for boost serialization
      friend class boost::serialization::access;

      //! Private method.
      //! Generates random vector of thresholds according within set ranges.
      void GenerateThresholdsVector();

      //! Private method.
      //! Generates random vector of features according within set ranges.
      void GenerateFeaturesVector();


      template<class Archive>
      void serialize(Archive & ar, const unsigned int version)
      {
        ar & thresholds_;
        ar & features_;
        ar & numFeatures_;
        ar & numThresholds_;
        ar & thresholdsLowRange_;
        ar & thresholdsHighRange_;
        ar & featuresLowRange_;
        ar & featuresHighRange_;
      }

      //!< Thresholds vector.
      std::vector<float> thresholds_;

      //!< Features vector.
      std::vector<Features> features_;

      //!< Number/size of features vector.
      int numFeatures_;

      //!< Number/size of thresholds vector.
      int numThresholds_;

      //!< Minimun range value for thresholds,
      float thresholdsLowRange_;

      //!< Maximum range value for thresholds,
      float thresholdsHighRange_;

      //!< Minimun range value for features,
      float featuresLowRange_;

      //!< Maximum range value for features,
      float featuresHighRange_;

      //!< Mersenne twister pseudo-random engine.
      //!< For generating ranndom numbers and seeds.
      static std::mt19937 mt_;
    };

  } /* bpc */
} /* rdf */

#endif /* FEATURESMAT_H */
