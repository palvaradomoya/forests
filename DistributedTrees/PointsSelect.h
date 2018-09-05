/*
 * File:   PointsSelect.h
 * Authors: Will
 *
 * Class: rdf::PointsSelect
 * Needs revision: Yes. Fix generatedPoints() and generatShoton() functions.
 * Description: This class handles the random points assignation to the
 * image points structure. Revision of the random selection process must
 * be done.
 *
 */

#ifndef POINTSSELECT_H
#define POINTSSELECT_H

#include <string>
#include <stdlib.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <vector>
#include "Estructura.h"

namespace rdf {

    /*
     * This class select points to each image
     */
    class PointsSelect {
    public:
        PointsSelect();
        PointsSelect(const PointsSelect& orig);
        virtual ~PointsSelect();

        //REVIEW: Check implementation.
        void generatedPoints(std::string type_Algorithm, std::vector<Estructura::Pixel>& points, int NumPoints, int height, int width, int NumTree);

    private:
      //REVIEW: What happens if same point is returned twice or more.
        void generatShoton(std::vector<Estructura::Pixel>& points, int NumPoints, int height, int width, int NumTree);

    };
}

#endif /* POINTSSELECT_H */
