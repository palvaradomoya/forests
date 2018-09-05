
/*
 * File:   ImageGetter.h
 *
 * Class: rdf::ImageGetter
 * Needs revision: Maybe.
 * Description: This class contains a method for reading tbe location of all
 * images from the database.The paths are read line by line, given a certain
 * range. Each line contains a path to a different image.
 */

#ifndef IMAGEGETTER_H
#define IMAGEGETTER_H




#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdio.h>



#define Width 320
#define Height 240

namespace rdf {
    /*
     * This class get the directiones of the images
     */
    class ImageGetter {
    public:
        ImageGetter();
        ImageGetter(const ImageGetter& orig);
        virtual ~ImageGetter();
        void readPath(std::vector<std::string>& directiones, int& cont, std::string path, int startRead, int endRead); // se encarga de leer el archivo que contiene las imagenes lo asigna a una aareglo input:arreglo, es llamado desde getStructure

    private:

    };
}

#endif /* IMAGEGETTER_H */
