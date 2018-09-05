/*
 * File:   Resource.h
 * Author: Wilberth Varela.
 *
 *  Class: rdf::Resource
 *  Needs revision: No, for the moment.
 *  Description: This class contains information about different types of
 *  resources. Such as: Total memory, total free memory and # of CPUs.
 */

#ifndef RESOURCE_H
#define RESOURCE_H
#include <iostream>
#include <boost/serialization/access.hpp>

namespace rdf {


    class Resource {
        private:
            friend class boost::serialization::access;
                template<class Archive>
                void serialize(Archive & ar, const unsigned int version)
                {
                    ar & MemTotal;
                    ar & MemFree;
                    ar & CPUs;
                    ar & Frequency;
                    ar & rank;
            }
           

        public:
            int MemTotal;
            int MemFree;
            int CPUs;
            int Frequency; //la velocidad es de kB
            int rank;
            Resource();
            Resource(const Resource& orig);

            virtual ~Resource();

            /**
             * This function displays the resource information of each node
             * from the cluster.
             */
            void displayResource();

            int getCPUs() const {
                return CPUs;
            }

            void setCPUs(int CPUs) {
                this->CPUs = CPUs;
            }

            int getFrequency() const {
                return Frequency;
            }
            //REVIEW: Why set frequency? What for?
            void setFrequency(int Frequency) {
                this->Frequency = Frequency;
            }

            int getMemFree() const {
                return MemFree;
            }

            void setMemFree(int MemFree) {
                this->MemFree = MemFree;
            }

            int getMemTotal() const {
                return MemTotal;
            }

            void setMemTotal(int MemTotal) {
                this->MemTotal = MemTotal;
            }




    };
}
#endif /* RESOURCE_H */
