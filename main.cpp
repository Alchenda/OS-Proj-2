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
#include <assert.h>
#include <fstream>
#include "prods_cons_MT.cpp"
#include <unistd.h>

using namespace std;

int bufferSize, pThread, cThread;



typedef struct {
    int threadNum;
} threadID;

typedef struct {
    int threadReturnID;
} threadReturnVals;

void *CreateProducer(void *prodArg) {

    threadID *args = (threadID *) prodArg;
    threadReturnVals *rvals = static_cast<threadReturnVals *>(malloc(sizeof(threadReturnVals)));
    int id = args->threadNum;
    assert(rvals != NULL);
    rvals->threadReturnID = id;

    cout << "P" << args->threadNum << ": Producing " << "CONST 4" << " values" << endl;

    return nullptr;
}

void *CreateConsumer(void *consArg) {

    threadID *args = (threadID *) consArg;
    threadReturnVals *rvals = static_cast<threadReturnVals *>(malloc(sizeof(threadReturnVals)));
    int id = args->threadNum;
    assert(rvals != NULL);
    rvals->threadReturnID = id;

    cout << "C" << id << ": Consumer " << "CONST 3" << " values" << endl;

    return (void *) rvals;
}


int main(int argc, char *argv[]) {

    threadID args = {-5};



    bufferSize = stoi(argv[1]); // size of buffer
    pThread = stoi(argv[2]); // number of producers to be produced
    cThread = stoi(argv[3]); //number of consumers to be produced

    pthread_t p;
    //myret_t *rvals;
    //myarg_t args = { 10, 20 };
    //pthread_create(&p, NULL, mythread, &args);
    //pthread_join(p, (void **) &rvals);

    //****************** Thread Creation *******************
    //Right when an object is created it will begin consuming/producing right away
    pthread_t producer, consumer;
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

//************ Thread Joining ***********

    threadReturnVals *rvals;

    for (int i = 0; i < pThread; ++i) { // join producers
        cout << "Main: producer " << i << " joined" << endl;
        pthread_join(producer, (void **) &rvals);


    }
    for (int i = 0; i < cThread; ++i) { //join consumers
        cout << "Main: consumer " << i << " joined" << endl;
        pthread_join(consumer, (void **) &rvals); // &rvals still not recognized yet.

    }

    cout << "Main: program completed" << endl;

    free(rvals);



    return 0;
}