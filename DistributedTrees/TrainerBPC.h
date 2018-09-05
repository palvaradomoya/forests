/*
 * File:   TrainerBPC.h
 * Author: Sygram
 *
 * Class: rdf::bpc::Trainer
 * Needs revision: Yes. Real implementation.
 * Description: Derived class. This class implements a definition of Train()
 * according to the shotton algorithm. rdf::Trainer is base class.
 *
 */

#ifndef TRAINERBPC_H
#define TRAINERBPC_H

#include "Trainer.h"
#include "Estructura.h"
#include "NodeTraineeBPC.h"

namespace rdf {
  namespace bpc {

    class Trainer : public rdf::Trainer{
    public:
      Trainer();
      Trainer(const Trainer& orig);
      void Train(Node*, std::vector<Estructura::Node>&, rdf::NodeResult&); //TODO - Finish implementation
      virtual ~Trainer();
    private:

    };

  } /* bpc */
} /* rdf */

#endif /* TRAINERBPC_H */
