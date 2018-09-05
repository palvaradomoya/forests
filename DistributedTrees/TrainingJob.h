/*
 * File:   TrainingJob.h
 * Author: Sygram
 *
 * Class: rdf::TrainingJob
 * Needs revision: Yes. Needs to be fully implemented.
 * Description: This class handles all the details needed for executing
 * and binding a training job/task.
 */

#ifndef TRAININGJOB_H
#define TRAININGJOB_H

#include "Trainer.h"


namespace rdf {

  class TrainingJob {
  public:
    TrainingJob();
    TrainingJob(const TrainingJob& orig);
    virtual ~TrainingJob();
  private:
    Trainer* trainer;

  };

} /* rdf */


#endif /* TRAININGJOB_H */
