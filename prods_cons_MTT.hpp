//
//  prods_cons_MTT.hpp
//  remakeeeee
//
//  Created by Danny Webb-McClain on 3/22/22.
//

#ifndef prods_cons_MTT_hpp
#define prods_cons_MTT_hpp

#include <stdio.h>
void Produce(int count, int threadNum);
void Consumer(int count, int threadNum);
void *CreateProducer(void *prodArg);
void *CreateConsumer(void *consArg);



#endif /* prods_cons_MTT_hpp */
