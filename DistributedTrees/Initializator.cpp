/*
 * File:   inicializator.cpp
 * Author: gabo
 *
 * 
 */

#include "Initializator.h"

rdf::Initializator::Initializator() {
    _config = new ConfigData(       VECTOR_AMOUNT,
                                THRESHOLD_AMOUNT,
                                TREE_AMOUNT,
                                PROCESS_AMOUNT,
                                TEST_IMAGES_AMOUNT,
                                TRAIN_IMAGES_AMOUNT,
                                LOG_VERBOSITY,
                                NOTICED_TIME,
                                TRAINNING_METHOD,
                                STOP_METHOD,
                                SELECTION_METHOD);
    _validator = new userValidator();
}

rdf::Initializator::Initializator(const Initializator& orig) {
}

void rdf::Initializator::createPlataform(){
    if(_validator->validateConfiguration(*_config)){
        cout << "Creating Plataform \n";
    }
    else {
        cout << "Error creating Plataform \n";
    }
}

rdf::Initializator::~Initializator() {
}
