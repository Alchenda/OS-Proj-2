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
prods_cons_MT::prods_cons_MT(){
    prodOrConNumber = 0;
    ID = NULL;
    toProdOrCon = 0;
}
void prods_cons_MT::produce(pthread_t prod){
    randomProduce = rand() % 6; //we can change this later for true randomness, it is good for now for seeing the test cases to match close to his
    while(buffer.size() < bufferSize){
        buffer.push(randomProduce);
    }
    //prod -> wait(); //I think you can see what I am trying to do here, I am trying to get the producer just to wait. Going to be honest I have been at this for a few hours now and not sure how to get this to work
}
void prods_cons_MT::consume(pthread_t con){
    
}
int prods_cons_MT::GetProdOrConNumber(){
    return prodOrConNumber;
}
char prods_cons_MT::GetID(){
    return ID;
}
int prods_cons_MT::GetAmount(){
    return toProdOrCon;
}
void prods_cons_MT::SetID(int myID){
    prodOrConNumber = myID; //unique number of producer or consumer
}
void prods_cons_MT::SetAmount(int amount){
    toProdOrCon = amount; //amount to produce only applies to producers
}
void prods_cons_MT::SetProdOrCon(char PorC){
    ID = PorC; //Identify if producer or consumer
}
void prods_cons_MT::ProducerStartPrint(){ //print message for when a producer is created
    cout << "P" << prodOrConNumber << ": Producing " << toProdOrCon << " values" << endl;
}
void prods_cons_MT::ConsumerStartPrint(){ //print message for when a consumer is created
    cout << "C" << prodOrConNumber << ":  Consuming" << toProdOrCon << " values" << endl;
}
