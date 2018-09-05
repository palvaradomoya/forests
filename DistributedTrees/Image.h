/*
 * File:   Image.h
 *
 * Class: Image
 * Needs revision: Yes. Refactor and more.
 * Description: This class generates the image point structure for the shotton
 * algorithm. It reads from a list of paths for loading depth and labeled
 * images.
 */

#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string>
#include "Estructura.h"
#include "Collection.h"
#include "LabelImage.h"
#include "DepthImage.h"

namespace rdf {

    /*
     * This class works to manager images to diferents algorithms
     */
    class Image {
    public:
        Image();
        Image(const Image& orig);
        virtual ~Image();
        void getStructura(std::vector<rdf::Estructura::Node>& structure, rdf::Estructura::DataMaster dataMaster);
    private:
      //! This function loads the images and points structure.
      //! FIXME: Needs revision.
        void generatedStructureShotton(std::vector<rdf::Estructura::Node>& structure,
                std::string type_Algorithm, int NumPoints, int height, int width,
                int NumTree, std::string pathDepth, std::string pathlabel,
                int startRead, int endRead, int tree, int node);

    };
}
#endif /* IMAGE_H */
