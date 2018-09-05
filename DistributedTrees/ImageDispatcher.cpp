/*
 * File:   ImageDispatcher.cpp
 * Author: gabo
 *
 *
 */

#include <vector>

#include "ImageDispatcher.h"
#include "Resource.h"

rdf::ImageDispatcher::ImageDispatcher() {
}

rdf::ImageDispatcher::ImageDispatcher(const ImageDispatcher& orig) {
    _imagesRanges = orig._imagesRanges;

}
rdf::ImageDispatcher::~ImageDispatcher() {}


int rdf::ImageDispatcher::analyzeResource(rdf::Resource &pResource) {
    // SOME KIND OF ANALYSIS OVER THE RESOURCE TO RETURN AN AMOUNT NUMBER OF IMAGES

    int memAvaibale = pResource.getMemFree(); // KB
    int imageSize   = IMAGE_SIZE; // 1 KB
    return memAvaibale / imageSize;

}


void rdf::ImageDispatcher::assignRanges(int pIntervals,bool pFlag) {
    if(pFlag){
            int multiple = TRAIN_IMAGES_AMOUNT/pIntervals;
            for(int i = 0 ; i < TRAIN_IMAGES_AMOUNT; i++){
                if(i%multiple == 0){
                    int a = i;
                    int b = i + multiple-1;
                    std::pair<int,int> range(a,b);
                    _imagesRanges.push_back(range);
                }
            }
    }

    else {
        int imageSum = 0;
        for(int i = 0; i< _resourceVector.size(); i++){
            Resource temp = _resourceVector[i];

            if(i==0){
                int imageAmount = analyzeResource(temp);
                int    a = i;
                int    b = i + imageAmount - 1;
                imageSum = imageAmount  + imageAmount;
                std::pair<int,int> range(a,b);
                _imagesRanges.push_back(range);
            }
            else {
                int imageAmount = analyzeResource(temp);
                std::pair<int,int> lastRange;
                lastRange = _imagesRanges.back();
                int a = lastRange.second+1;
                int b = lastRange.second + imageAmount-1;
                imageSum = imageAmount  + imageAmount;
                std::pair<int,int> range(a,b);
                _imagesRanges.push_back(range);

            }

        }
    }
}

void rdf::ImageDispatcher::showRanges() {
    for(int i = 0 ; i < _imagesRanges.size(); i++){
        std::cout << "Node " << i+1 << ": [" <<_imagesRanges[i].first <<"," << _imagesRanges[i].second << "] \n";
    }
}

void rdf::ImageDispatcher::addResource(rdf::Resource& pResource) {
    _resourceVector.push_back(pResource);


}
