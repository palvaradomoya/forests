/*
 * File:   ImageOperations.h
 * Author: Sygram
 *
 * Class: rdf::ImageOperations
 * Needs revision: Needs further improvement. Maybe implement new operations.
 * Description: This class implements a set of operations that can be applied
 * to the points vector structure. For example:
 * AssignTreeFlagsToImagesSet(): Is the function responsible for assigning
 * trees availability flag to each image.
 */

#ifndef IMAGEOPERATIONS_H
#define IMAGEOPERATIONS_H

#include <random>
#include "Estructura.h"


namespace rdf {

  class ImageOperations {
  public:

    //<! Constructor
    ImageOperations();

    //<! Copy Constructor
    ImageOperations(const ImageOperations& orig);

    /*!
      * Assigns a set of random trees availability flags according to a percentage.
      * It aslo spreads the percentages among the number of trees.
      * \param percentage Percentage of the set of images for each tree.
      * \param numTrees Number of trees.
      * \param &imagesSet Images with points structure vector.
      */
    void SetImagesDistribution(
      std::vector<Estructura::Node>& imagesSet, int percentage, int numTrees);
    virtual ~ImageOperations();
  private:

    //<! Sets trees availability flag to an image according to the given
    //<! percentage.
    void AssignTreeFlagsToImagesSet(
      std::vector<Estructura::Node>& imagesSet, int percentageNum,
      int treeNum, int totalSize);

    //<! Static function for initializing seed for random distribution.
    //<! It is only initialized once.
    static std::mt19937 InitRandomSeed();

    //<! MersenneTwister pseudo-random engine
    static std::mt19937 mt_;

  };

} /* rdf */

#endif /* IMAGEOPERATIONS_H */
