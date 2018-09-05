/*
 * File:   StrategyImage.h
 * 
 * Class: StrategyImage
 * Needs revision: Minimal.
 * Description: Abstract class for images handling. It defines an interface
 * for READING images of different kinds.
 * DepthImage and LabelImage classes inherit from this class.
 *
 */

#ifndef STRATEGYIMAGE_H
#define STRATEGYIMAGE_H
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <fstream>      // std::ifstream
#include <iostream>     // std::cout

namespace rdf {
    /*
     * This class implements methods abstract to the load image
     */
    class StrategyImage {
    public:
        StrategyImage();
        StrategyImage(const StrategyImage& orig);
        virtual ~StrategyImage();
        virtual void readImage(int heigth, int width, std::string direction, cv::Mat& image) = 0;
    private:

    };
}

#endif /* STRATEGYIMAGE_H */
