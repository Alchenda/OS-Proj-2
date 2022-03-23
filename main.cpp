//
//  main.cpp
//  OSProj2
//
//  Created by Danny Webb-McClain on 3/17/22.
//

#include <iostream>
#include <pthread.h>
#include <mutex>
#include <queue>
#include <fstream>
#include <unistd.h>
//#include <condition_variable>
#include "prods_cons_MTT.hpp"

using namespace std;
queue<int> buffer;
//mutex lock1;
int bufferSize, pThread, cThread;
//condition_variable is_full;
//condition_variable is_empty;
pthread_cond_t NAME;
pthread_mutex_t lock1;

/*void Produce();
void Consumer();
void *CreateProducer(void *prodArg);
void *CreateConsumer(void *consArg);*/

typedef struct {
    int threadNum;
} threadID;
void *CreateProducer(void *prodArg) {

    threadID *args = (threadID *) prodArg;
    cout << "P" << args->threadNum << ": Producing " << "CONST 4" << " values" << endl;
    Produce(bufferSize * 2);
    return nullptr;
}

void *CreateConsumer(void *consArg) {

    threadID *args = (threadID *) consArg;
    cout << "C" << args->threadNum << ": Consumer " << "CONST 3" << " values" << endl;

    return nullptr;
}





int main(int argc, const char * argv[]) {
    pthread_cond_init(&NAME, NULL);
    pthread_mutex_init(&lock1, NULL);
    threadID args = {-5};

    bufferSize = stoi(argv[1]); // size of buffer
    pThread = stoi(argv[2]); // number of producers to be produced
    cThread = stoi(argv[3]); //number of consumers to be produced

    
    pthread_t producer, consumer;
    //****************** Thread Creation *******************
    //Right when an object is created it will begin consuming/producing right away
    for (int i = 0; i < pThread; ++i) { //create all of the producers

        args = {i};
        cout << "Main: started producer " << i << endl;
        pthread_create(&producer, nullptr, CreateProducer, &args);
    }

    for (int i = 0; i < cThread; ++i) { //create all of the consumers
        args = {i};
        cout << "Main: started consumer " << i << endl;
        pthread_create(&consumer, nullptr, CreateConsumer, &args);
    }
    sleep(1);
    return 0;
}
