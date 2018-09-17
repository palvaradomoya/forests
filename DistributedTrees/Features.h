/*
 * File:   Features.h
 * Author: Sygram
 *
 * Class: rdf::bpc::Features
 * Needs revision: Probably not.
 * Description: This class is used to represent the shotton features that
 * are included at each index of the random matrix. This class is used by
 * FeaturesMat to load a vector of Features, which are later used by nodes
 * during training stage. This class is serializable.
 *
 */

#ifndef FEATURES_H
#define FEATURES_H

#include <opencv2/core/core.hpp>
#include <opencv2/core/types_c.h>
#include <utility>

// include headers that implement a archive in simple text format
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>


namespace rdf {
    namespace bpc {

        typedef CvPoint2D32f Feature; ///< Feature is equivalent to a CV point 32-bit float.

        class Features {
        public:
            Features();
            Features(float, float, float, float);
            Features(const Features& orig);
            virtual ~Features();
            std::pair<Feature, Feature> GetFeatures(){}; //TODO

            /* Data members */
            Feature feature1_;  ///< Data member for first feature.
            Feature feature2_;  ///< Data member for second feature.
            Feature SetFeature1(float x, float y);
            Feature SetFeature2(float x, float y);
            float GetFeature1X();
            float GetFeature1Y();
            float GetFeature2X();
            float GetFeature2Y();
            float x1;
            float y1;
            float x2;
            float y2;
        private:

          /* --- Serialization --- */
          friend class boost::serialization::access;
          template<class Archive>
          void serialize(Archive & ar, const unsigned int version)
          {
            ar & x1;
            ar & y1;
            ar & x2;
            ar & y2;
            // ar & feature1_.x;
            // ar & feature1_.y;
            // ar & feature2_.x;
            // ar & feature2_.y;
          }
          /* ==== Serialization ==== */

        };

    } /* bpc */
} /* rdf */

#endif /* FEATURES_H */
