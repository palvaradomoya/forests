
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include "TrainManager.h"
#include "Resources.h"


using namespace rdf;

int main(int argc, char** argv){



      // rdf::DistributionManager _manager;
      // _manager.transferMatrices(4);

      Task myTask;
      Task myTask2;
      bpc::FeaturesMat feat;
      bpc::FeaturesMat feat2;
      bpc::FeaturesMat feat3;
      bpc::FeaturesMat feat4;
      feat.SetThresholdsNumRange(20, 200);
      feat.SetFeaturesNumRange(20, 200);
      feat.SetMatrixSize(2,2);
      feat.GenerateVectors();
      feat2.SetThresholdsNumRange(200, 400);
      feat2.SetFeaturesNumRange(200, 400);
      feat2.SetMatrixSize(2,2);
      feat2.GenerateVectors();
      std::cout << "------------------------------------------" << std::endl;
      std::cout << "------------------------------------------" << std::endl;
      feat.Print();
      std::cout << "------------------------------------------" << std::endl;
      std::cout << "------------------------------------------" << std::endl;
      // feat2 = feat;
      std::cout << "+++++++++++++++++++++++++++++++++++++++++++" << std::endl;
      std::cout << "+++++++++++++++++++++++++++++++++++++++++++" << std::endl;
      feat2.Print();
      std::cout << "+++++++++++++++++++++++++++++++++++++++++++" << std::endl;
      std::cout << "+++++++++++++++++++++++++++++++++++++++++++" << std::endl;


      myTask.setTree(1);
      myTask.setNode(1);
      myTask.setFeatureMatrix(feat2);
      // myTask2.setFeatureMatrix(feat);



      std::cout << "==========================================" << std::endl;
      std::cout << "==========================================" << std::endl;
      myTask.getFeatureMatrix().Print();
      std::cout << "==========================================" << std::endl;
      std::cout << "==========================================" << std::endl;

      // myTask2 = myTask;
      // feat3 =  myTask.getFeatureMatrix();
      // myTask2.getFeatureMatrix().Print();

      std::ofstream ofs( "store.dat" );
      // Save filename data contained in Info object
      {
        // Create an output archive
        // std::ofstream ofs( "store.dat" );
        boost::archive::text_oarchive oa(ofs);
        // Save the data
        oa << feat;
      }

      // Restore from saved data and print to verify contents
      {
          // Create and input archive
          std::ifstream ifs( "store.dat" );
          boost::archive::text_iarchive ia(ifs);

          // Load the data
          ia >> feat2;
      }
      std::cout << "\n\n\n\n";
      // myTask2.getFeatureMatrix().Print();
      feat.Print();
      std::cout << "\n\n";
      feat2.Print();
      // myTask.getFeatureMatrix().Print();
      std::cout << "\n\n";



      // feat3.Print();



// std::cout << "Hello worlds!s" << '\n';
   //  rdf::TrainManager _trainer;
   //  _trainer.validateConfiguration();
   //  _trainer.initPlatform();
   //  _trainer.sendingNodes();
   // _trainer.sendingResults();

    // rdf::DistributionManager _manager;
    // _manager.transferResources();
    //
    // _manager.transferRanges();
    //
    // rdf::Task _task;
    // _task.setRank(1);
    // _task.setTree(1);
    // _task.setNode(2);
    // _task.setStatus(0);

    // _manager.transferNodes(_task);

   // _manager.transferNodes(_task2);
   // _manager.transferNodes(_task3);
   // _manager.transferNodes(_task4);
   // _manager.transferNodes(_task5);
   // _manager.transferNodes(_task6);

   // _manager.transferResults();





   //
   // bpc::FeaturesMat featMat1;
   //
   // featMat1.SetThresholdsNumRange(20, 200);
   // featMat1.SetFeaturesNumRange(20, 200);
   // featMat1.SetMatrixSize(2,2);
   // featMat1.GenerateVectors();
   // std::cout << "------------------------------------------" << std::endl;
   // std::cout << "------------------------------------------" << std::endl;
   // featMat1.Print();
   // std::cout << "===========================================" << std::endl;
   // std::cout << "===========================================" << std::endl;
   //
   // bpc::FeaturesMat featMat2;
   // featMat2 = featMat1;
   // std::cout << "------------------------------------------" << std::endl;
   // std::cout << "------------------------------------------" << std::endl;
   // featMat2.Print();
   // std::cout << "===========================================" << std::endl;
   // std::cout << "===========================================" << std::endl;
   //


  return 0;
}
