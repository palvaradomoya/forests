/*
 * File:   TrainManager.h
 * Author: gabo
 *
 * Class: rdf::TrainManager
 * Needs revision: Yes. Needs further implementation.
 * Description: This class is intended to handle the Global Training Process
 * in order to make sure everything is executed correctly according to the
 * initial configuration parameters.
 */

#include <iostream>
#include <string>
#include <vector>
#include "Task.h"
#include <tuple>
#include <stdlib.h>
#include <unistd.h>
#include "DistributionManager.h"
#include "Initializator.h"
#include "ForestManager.h"

#include <fstream>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>
#include <stdio.h>
#include <omp.h>
#include <cmath>
#include "ImageGetter.h"
#include "Collection.h"
#include "LabelImage.h"
#include "DepthImage.h"
#include "Estructura.h"
#include "PointsSelect.h"
#include "Image.h"


#ifndef TRAINMANAGER_H
#define TRAINMANAGER_H

namespace rdf {

    class TrainManager {
    public:
        TrainManager();
        TrainManager(const TrainManager& orig);
        virtual ~TrainManager();
        bool validateConfiguration();
        bool initPlatform();
        void sendingNodes();
        void trainningNodes();
        void listeningResults();
        void sendingResults();

    private:
        Initializator            _initializator;
        rdf::DistributionManager _distributor;
        //rdf::ForestManager            _manager;;
    };
}

#endif /* TRAINMANAGER_H */
