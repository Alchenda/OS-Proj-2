//
//  prods_cons_MT.cpp
//  OSProj2
//
//  Created by Danny Webb-McClain on 3/17/22.
//
#include <queue>
#include <fstream>
#include "prods_cons_MT.hpp"

//pretty sure this entire constructor is useless
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
void prods_cons_MT::produce(){
    
}
void prods_cons_MT::consume(){
    
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
