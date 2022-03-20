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

using namespace std;
queue<int> buffer;
mutex lock;
int bufferSize;

int main(int argc, const char * argv[]) {
    int pThread, cThread;
    bufferSize = stoi(argv[1]); // size of buffer
    pThread = stoi(argv[2]); // umber of producers to be produced
    cThread = stoi(argv[3]); //number of consumers to be produced
    //****************** Dynamic Memory Allocation *******************
    prods_cons_MT *Producers; //Dynamic memory allocation of Producers
    prods_cons_MT *Consumers; //Dynamic memory allocation of Consumers
    pthread_t *prod; //Dynamic memory allocation for Producer Threads
    pthread_t *con; //Dynamic memory allocation for Consumer Threads
    Producers = new prods_cons_MT[pThread];  //create an array of the number of producers
    Consumers = new prods_cons_MT[cThread]; //create an array of the number of consumers
    prod = new pthread_t[pThread]; // create an array of producer threads
    con = new pthread_t[cThread]; // create an array of consumer threads
    //****************** Object Creation *******************
    //Right when an object is created it will begin consuming/producing right away
    for (int i = 0; i < pThread; ++i) { //create all of the producers
        Producers[i].SetID(i); //which number the producer is
        Producers[i].SetAmount(bufferSize * 2); //this is to ensure over production
        Producers[i].SetProdOrCon('P'); //indicate it is a producer
        cout << "Main: started producer " << i;
        Producers[i].ProducerStartPrint();
        Producers[i].produce(prod[i]); //producer thread begins production
    }
    for (int i = 0; i < cThread; ++i){ //create all of the consumers
        Consumers[i].SetID(i); //which number the consumer is
        Consumers[i].SetAmount(cThread); //amount to consume
        Consumers[i].SetProdOrCon('C'); //indicate it is a consumer
        cout << "Main: started consumer " << i;
        Consumers[i].consume(con[i]); //consumer thread begins consuming
    }
    return 0;
}
