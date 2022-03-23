# OS-Proj-2
#### Danny Webb-McClain and Florinda Martinez

##Second group project for Operating Systems

The purpose of OSProj2 is to provide a review on multithreading and synchronization. This was done so by ultizing pthreads in order to create a multi-threaded version of the producer-consumer model. Additionally, a buffer will be used in order to manage the shared queue that takes place among the producer and consumer.

## Installation

1. Download the zip file from blackboard.
2. Extract the zip file to a file location of your choosing.
3. Open up your terminal.
4. Change your directory to where you extracted the file. And keep changing your directory till you are inside the cmake_build_debug folder.

```bash
cd OS-Proj-2-master/cmake-build-debug
```
5. Run the code by typing the following command in terminal. The variables x, y, z represent the input value of the buffer size, producers and consumers. The minimal value needed is 1 while there is no defined maximum.

```bash
./OS-Proj-2 x y z 
```

## Notes
This was run through X2GO in order to virtual test on Linux and tested in X2GO as well as MacOS 11.6.1.
