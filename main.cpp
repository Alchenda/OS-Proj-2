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
#include "prods_cons_MT.cpp"
#include <unistd.h>

using namespace std;
queue<int> buffer;
mutex lock;
int bufferSize, pThread, cThread;;


typedef struct {
    int threadNum;
} threadID;

typedef struct {
    int threadReturn
} returnThread;

void *CreateProducer(void *prodArg) {

    threadID *args = (threadID *) prodArg;
    cout << "P" << args->threadNum << ": Producing " << "CONST 4" << " values" << endl;

    return nullptr;
}

void *CreateConsumer(void *consArg) {

    threadID *args = (threadID *) consArg;
    returnThread *rvals;
    int id = args->threadNum;

    rvals->threadReturn = id;
    cout << "C" << id << ": Consumer " << "CONST 3" << " values" << endl;

    return (void *) rvals
}




int main(int argc, const char * argv[]) {

    threadID args = {-5};

    bufferSize = stoi(argv[1]); // size of buffer
    pThread = stoi(argv[2]); // number of producers to be produced
    cThread = stoi(argv[3]); //number of consumers to be produced

    /*
    //****************** Dynamic Memory Allocation *******************
    prods_cons_MT *Producers; //Dynamic memory allocation of Producers
    prods_cons_MT *Consumers; //Dynamic memory allocation of Consumers
    pthread_t *prod; //Dynamic memory allocation for Producer Threads
    pthread_t *con; //Dynamic memory allocation for Consumer Threads
    Producers = new prods_cons_MT[pThread];  //create an array of the number of producers
    Consumers = new prods_cons_MT[cThread]; //create an array of the number of consumers
    prod = new pthread_t[pThread]; // create an array of producer threads
    con = new pthread_t[cThread]; // create an array of consumer threads
     */
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



    //************ Thread Joining ***********

    for (int i = 0; i < pThread; ++i) { // join producers
        cout << "Main: producer " << i << " joined" << endl;
        pthread_join(producer, nullptr);


    }
    for (int i = 0; i < cThread; ++i) { //join consumers
        cout << "Main: consumer " << i << " joined" << endl;
        pthread_join(consumer, (void **) &rvals); // &rvals still not recognized yet.

    }

    cout << "Main: program completed" << endl;

    sleep(1);
    return 0;
}
