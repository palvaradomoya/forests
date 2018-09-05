/*
 * File:   Trainer.h
 * Author: Sygram
 *
 * Class: rdf::Trainer
 * Needs revision: Yes. Maybe define more standard function.
 * Description: Pure abstract class. Template for implementing all Training
 * Algorithms. This class acts as a Strategy Pattern for the training interface.
 *
 */

#ifndef TRAINER_H
#define TRAINER_H

#include <vector>

#include "Node.h"
#include "Estructura.h"
#include "NodeResult.h"


namespace rdf {

  class Trainer {
  public:
    Trainer();
    Trainer(const Trainer& orig);
    virtual void Train(Node*, std::vector<Estructura::Node>&, NodeResult&) = 0;
    virtual ~Trainer();
  private:

  };

} /* rdf */


#endif /* TRAINER_H */
