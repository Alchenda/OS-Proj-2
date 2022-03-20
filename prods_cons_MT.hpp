//
//  prods_cons_MT.hpp
//  OSProj2
//
//  Created by Danny Webb-McClain on 3/17/22.
//

#ifndef prods_cons_MT_hpp
#define prods_cons_MT_hpp
#include <pthread.h>
#include <stdio.h>
class prods_cons_MT{
public:
    prods_cons_MT();
    prods_cons_MT(int myID, char PorC, int amount);
    void consume(pthread_t con); //function to preform consumption
    void produce(pthread_t prod); //function to preform production
    int GetProdOrConNumber(); //retrieve what number producer or consumer it is
    char GetID(); //retrieve whether it is a producer or consumer
    int GetAmount(); //retrieve the amount to produce or consume
    void ProducerStartPrint(); //prints out required start message of producer
    void ConsumerStartPrint(); //prints out required start message of consumer
    void SetID(int myID);
    void SetAmount(int amount);
    void SetProdOrCon(char PorC);
private:
    int prodOrConNumber; //unique number for each producer/consumer
    char ID; //identify if producer/consumer
    int toProdOrCon; //the amount to be produced or consumed
    int randomProduce; //random integer that is to be produced by each producer to buffer
};
#endif /* prods_cons_MT_hpp */
