//
//  prods_cons_MT.cpp
//  OSProj2
//
//  Created by Danny Webb-McClain on 3/17/22.
//
#include <queue>
#include <fstream>
#include <iostream>
#include <time.h>
#include "prods_cons_MT.hpp"
using namespace std;
extern queue<int> buffer; //shared queue
extern int bufferSize; //shared size of buffer
//this constructor is actually not used

prods_cons_MT::prods_cons_MT(int myID, char PorC, int amount){
    prodOrConNumber = myID; //unique number for each producer/consumer
    ID = PorC; //identify if producer/consumer
    toProdOrCon = amount; // the amount to be produced or consumed
}

