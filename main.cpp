//
//  main.cpp
// OS-Proj-2
// Danny Webb-McClain and Florinda Martinez
//

#include <iostream>
#include <pthread.h>
#include <mutex>
#include <queue>
#include <fstream>
#include <unistd.h>
#include <condition_variable>
#include "prods_cons_MTT.hpp"

using namespace std;
queue<int> buffer;
//mutex lock1;
int bufferSize, pThread, cThread, qTrack, prodTrack, extraConsume;
bool specialConsumer;
//condition_variable is_full;
//condition_variable is_empty;
pthread_cond_t IS_FULL, IS_EMPTY;
pthread_cond_t NAME;
pthread_mutex_t lock1;

typedef struct {
    int threadNum;
} threadID;

int main(int argc, const char * argv[]) {
    int qTrack = -1; //used for consumer thread position tracking
    int prodTrack = -1; //used for producer thread position tracking
    pthread_cond_init(&IS_FULL, NULL);
    pthread_cond_init(&IS_EMPTY, NULL);
    pthread_mutex_init(&lock1, NULL);
    threadID args = {-5};
    bool specialConsumer = false; //used for the consumer that should take extra consumptions

    bufferSize = stoi(argv[1]); // size of buffer
    pThread = stoi(argv[2]); // number of producers to be produced
    cThread = stoi(argv[3]); //number of consumers to be produced

    
    pthread_t producer, consumer;
    //****************** Thread Creation *******************
    //Right when an object is created it will begin consuming/producing right away
    for (int i = 0; i < pThread; ++i) { //create all of the producers

        args = {i};
        pthread_mutex_lock(&lock1);
        cout << "Main: started producer " << i << endl;
        pthread_mutex_unlock(&lock1);
        pthread_create(&producer, nullptr, CreateProducer, &args);
    }

    for (int i = 0; i < cThread; ++i) { //create all of the consumers
        args = {i};
        pthread_mutex_lock(&lock1);
        cout << "Main: started consumer " << i << endl;
        pthread_mutex_unlock(&lock1);
        if (i == (cThread - 1)) {
            specialConsumer = true;
        }
        pthread_create(&consumer, nullptr, CreateConsumer, &args);
    }


    sleep(1);
    return 0;
}
