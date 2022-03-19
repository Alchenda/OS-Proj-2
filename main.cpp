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

int main(int argc, const char * argv[]) {
    int pThread, cThread, bufferSize;
    bufferSize = stoi(argv[1]); // size of buffer
    pThread = stoi(argv[2]); // number of producers to be produced
    cThread = stoi(argv[3]); // number of consumers to be produced
    prods_cons_MT Producers[pThread]; //create an array of the number of producers
    prods_cons_MT Consumers[cThread]; //create an array of the number of consumers
    return 0;
}
