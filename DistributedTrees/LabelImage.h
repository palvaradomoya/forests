/*
 * File:   LabelImage.h
 *
 * Class: rdf::LabelImage
 * Needs revision: Probably not.
 * Description: This class implements readImage() abstract method in order
 * to read a label image
 *
 */

#ifndef LABELIMAGE_H
#define LABELIMAGE_H

#include <iostream>
#include "StrategyImage.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace rdf {

    class LabelImage : public StrategyImage {
    public:
        LabelImage();
        LabelImage(const LabelImage& orig);
        virtual ~LabelImage();
        virtual void readImage(int height, int width, std::string direction, cv::Mat& image);


    private:

    };
}

#endif /* LABELIMAGE_H */
