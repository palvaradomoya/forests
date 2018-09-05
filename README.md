# forests
General framework for random forests.

This project started in May 2018 is intended to provide a general framework for training, testing and use several architectures of random forest in the context of image labeling and pose estimation.  Other great projects, such as CURFIL (https://github.com/deeplearningais/curfil), are useful as long as your data fits in your available memory. 

The current project is intended to use all available resources of a computer cluster to extend the number of images to be used in a training session and accelerate the training processing by means of distribution of the tasks in to several nodes.

It is still in a very early implementation stage and it will take a long time until it is usable.

The first fully functional distributed implementation of the body-part classification approach proposed by Shotton et al. will be hopefully available by the end of 2018.

Copyright 2018.  Tecnológico de Costa Rica, SIPLab



Set up:

sudo apt update
sudo apt upgrade
sudo apt install build-essential git scons cmake pkg-config
sudo apt install libopencv-dev python-opencv
sudo apt install mpich
sudo apt install libboost-all-dev

