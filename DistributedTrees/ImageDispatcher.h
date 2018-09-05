/*
 * File:   ImageDispatcher.h
 * Author: gabo
 *
 *  Class: rdf::ImageDispatcher
 *  Needs revision: Yes. Ranges assignation function must be revised.
 *                  analyzeResource() needs revision.
 *                  Also review pair vectors for imagesRanges
 *  Description: This class is intended to work as a load balancer. According
 *  to the available resources from each slave node.
 */




#ifndef IMAGEDISPATCHER_H
#define IMAGEDISPATCHER_H

#include "NodeResource.h"
#include "Config.h"
#include "Resource.h"

#define IMAGE_SIZE 10000 //!< 1 KB

namespace rdf {
     /**
        *  This class identifies resources (MemFree) from all different nodes
        *  to assign a valid number of images for training. This class is
        *  similar to a load balancer.
        */
    class ImageDispatcher {

    public:

        //!< Constructor
        ImageDispatcher();

        //!< Copy Constructor
        ImageDispatcher(const ImageDispatcher& orig);

        //!< Destructor
        virtual ~ImageDispatcher();

        /**
         * This function intents analyze resource from each nodes in order to determinate how many images can charge
         * \param pResource : object that contains information about available memory in the node.
         * \return int : it is the number of images that can charge.
         */
         //REVIEW
        int analyzeResource(rdf::Resource &pResource);


        /**
         * This function assing the same number of images for each process and save them in a vector with a std::pair object
         * @param pIntervals : how many process or intervals.
         */
         //REVIEW
        void assignRanges(int pIntervals,bool pFlag);

        //!< Adds new resource to vector of resources (_resourceVector)
        void addResource(rdf::Resource &pResource);

        //!< Shows each pair of images ranges
        //REVIEW
        void showRanges();

        std::vector<std::pair<int, int> > getImagesRanges() const {
            return _imagesRanges;
        }
        void setImagesRanges(std::vector<std::pair<int, int> > _imagesRanges) {
            this->_imagesRanges = _imagesRanges;
        }

    private:
        std::vector<std::pair<int,int>>     _imagesRanges;//REVIEW          /*!< Allow to save assigned image ranges */
        std::vector<rdf::Resource>          _resourceVector;
    };
}

#endif /* IMAGEDISPATCHER_H */
