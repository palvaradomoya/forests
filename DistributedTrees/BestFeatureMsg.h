/*
 * File:   BestFeatureMsg.h
 * Author: gabo
 *
 * Class: rdf::rdf::BestFeatureMsg
 * Needs revision: Yes. Lacking real implementation.
 * Description: This class is used to send the best feature message, to all
 * slave nodes. Needs further implementation, best feature selection is not
 * implemented.
 *
 */


#ifndef BESTFEATUREMSG_H
#define BESTFEATUREMSG_H

#include "Features.h"

namespace rdf {

namespace bpc {

class BestFeatureMsg {
public:
BestFeatureMsg();
BestFeatureMsg(const BestFeatureMsg& orig);
virtual ~BestFeatureMsg();


float GetThreshold() const {
        return _threshold;
}

void SetThreshold(float _threshold) {
        this->_threshold = _threshold;
}
Features GetFeature() const {
        return _feature;
}

void SetFeature(Features _feature) {
        this->_feature = _feature;
}

int GetNodeNumber() const {
        return _nodeNumber;
}

void SetNodeNumber(int _nodeNumber) {
        this->_nodeNumber = _nodeNumber;
}

int GetTreeNumber() const {
        return _treeNumber;
}

void SetTreeNumber(int _treeNumber) {
        this->_treeNumber = _treeNumber;
}


private:
friend class boost::serialization::access;
template<class Archive>
void serialize(Archive & ar, const unsigned int version)
{
        ar & _feature;
        ar & _threshold;
        ar & _treeNumber;
        ar & _nodeNumber;
}
Features _feature;
float _threshold;
int _treeNumber;
int _nodeNumber;


};

}
}

#endif /* BESTFEATUREMSG_H */
