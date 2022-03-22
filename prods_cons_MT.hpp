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
    prods_cons_MT(int myID, char PorC, int amount);



private:
    int prodOrConNumber; //unique number for each producer/consumer
    char ID; //identify if producer/consumer
    int toProdOrCon; //the amount to be produced or consumed
};

#endif /* prods_cons_MT_hpp */
