/*
 * File:   QueueThread.h
 * Author: will
 *
 * Class: rdf::QueueThread
 * Needs revision: Yes. Training algorithm call and init() function.
 * Description: Class partially understood. This queue class runs the shotton
 * training algorithm as one of it's tasks.
 *
 */

#ifndef QUEUETHREAD_H
#define QUEUETHREAD_H

#include <thread>
#include <vector>
#include <mutex>              // std::mutex, std::unique_lock
#include <queue>
#include <condition_variable> // std::condition_variable

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "Estructura.h"
#include "Task.h"
#include "NodeResult.h"
#include "Scheduler.h"

namespace rdf {

    class Scheduler; //Forward declaration

    /*
     * This class control to each thread with its respective task
     */

    class QueueThread {
    public:
        QueueThread();
        QueueThread(const QueueThread&);
        // QueueThread() : schedulerRef_(schedulerRef_) {};
        // QueueThread(Scheduler& sched) : schedulerRef_(sched) { };
        // QueueThread(const QueueThread& orig);
        // QueueThread(const QueueThread&& orig);
        virtual ~QueueThread();
        std::thread thread;
        std::mutex mtx;
        std::condition_variable cv;
        bool ready = false;
        std::vector<Estructura::Node> structure;
        rdf::Task task;
        std::priority_queue<rdf::Task> tasks;
        rdf::NodeResult nodeResult;
        // Scheduler& schedulerRef_;


        void run();

        void connect(std::vector<Estructura::Node> structure,  rdf::Task task, std::priority_queue<rdf::Task> tasks,
                rdf::NodeResult &nodeResult);





    private:

        void sync();

    };
}

#endif /* QUEUETHREAD_H */
