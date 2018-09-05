/*
 * File:   initializator.h
 * Author: gabo
 *
 * Class: rdf::Initializator
 * Needs revision: Yes. Up for deletion/Complete rework.
 * Description: This class loads the global configuration values into
 * a ConfigData class. Currently this is done via GLOBAL VARIABLES.
 * REVIEW: IMPLEMENTATION NEEDS REWORK.
 *
 */

#include "Config.h"
#include "ConfigData.h"
#include "ConfigValidationInterface.h"
#include "userValidator.h"


#ifndef INITIALIZATOR_H
#define INITIALIZATOR_H

namespace rdf {
    /* This class allow to initialize the platform
        */
    class Initializator {

        private:
            ConfigData                  *_config;
            ConfigValidationInterface   *_validator;

        public:
            Initializator();
            Initializator(const Initializator& orig);
            Initializator(const ConfigData &Data);
            virtual ~Initializator();

            void createPlataform();


    };
}
#endif /* INITIALIZATOR_H */
