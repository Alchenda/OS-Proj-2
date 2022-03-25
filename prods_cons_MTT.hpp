//
//  prods_cons_MTT.hpp
//  remakeeeee
//OS-Proj-2
//Danny Webb-McClain and Florinda Martinez
//

#ifndef prods_cons_MTT_hpp
#define prods_cons_MTT_hpp

#include <stdio.h>
void Produce(int count, int threadNum);
void Consume(int count, int threadNum);
void *CreateProducer(void *prodArg);
void *CreateConsumer(void *consArg);



#endif /* prods_cons_MTT_hpp */
