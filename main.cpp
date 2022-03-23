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
int bufferSize, pThread, cThread, qTrack, prodTrack, extraConsume;
bool specialConsumer;
//condition_variable is_full;
//condition_variable is_empty;
pthread_cond_t NAME;
pthread_mutex_t lock1;

/*void Produce();
void Consumer();
void *CreateProducer(void *prodArg);
void *CreateConsumer(void *consArg);*/
//**********Important please read the comment below, thank you!****************
//please move all of this into the prods_cons_MTT.cpp file, it is not allowed to be in here for final submission.I think the only prototype missing is for the struct in the header file.
typedef struct {
    int threadNum;
} threadID;
void *CreateProducer(void *prodArg) {

    threadID *args = (threadID *) prodArg;
    pthread_mutex_lock(&lock1);
    cout << "P" << args->threadNum << ": Producing " << (bufferSize * 2) << " values" << endl;
    pthread_mutex_unlock(&lock1);
    int thready = args -> threadNum; //I hope it works how I think it works
    Produce(bufferSize * 2, thready);
    return nullptr;
}

void *CreateConsumer(void *consArg) {
    
    threadID *args = (threadID *) consArg;
    if (specialConsumer) { //this is the case for when there needs to be a special consumer that does extra
        extraConsume = ((bufferSize * 2) * pThread) % cThread; //total of production modulated with total consumers to get leftover produce
        pthread_mutex_lock(&lock1);
        cout << "C" << args->threadNum << ": Consumer " << extraConsume << " values" << endl;
        pthread_mutex_unlock(&lock1);
        int thready = args -> threadNum; //I hope this works how I think it works
        Consume(extraConsume, thready);
        return nullptr;
    } else{ //regular consumers
        cout << "C" << args->threadNum << ": Consumer " << cThread << " values" << endl;
        int thready = args -> threadNum; //I hope this works how I think it works
        Consume(cThread, thready);
    }
    
    return nullptr;
}





int main(int argc, const char * argv[]) {
    int qTrack = -1; //used for consumer thread position tracking
    int prodTrack = -1; //used for producer thread position tracking
    pthread_cond_init(&NAME, NULL);
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
        cout << "Main: started producer " << i << endl;
        pthread_create(&producer, nullptr, CreateProducer, &args);
    }

    for (int i = 0; i < cThread; ++i) { //create all of the consumers
        args = {i};
        cout << "Main: started consumer " << i << endl;
        if (i == (cThread - 1)) {
            specialConsumer = true;
        }
        pthread_create(&consumer, nullptr, CreateConsumer, &args);
    }
    sleep(1);
    return 0;
}
