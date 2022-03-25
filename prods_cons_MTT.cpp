//
//  prods_cons_MTT.cpp
//  remakeeeee
//OS-Proj-2
//Danny Webb-McClain and Florinda Martinez
//
#include <iostream>
#include <pthread.h>
#include <mutex>
#include <queue>
#include <fstream>
#include <unistd.h>
#include "prods_cons_MTT.hpp"
using namespace std;
extern pthread_cond_t IS_EMPTY, IS_FULL;
extern pthread_cond_t NAME;
extern pthread_mutex_t lock1;
extern queue<int> buffer;
extern int bufferSize, pThread, cThread, qTrack, prodTrack, extraConsume;
extern bool specialConsumer;

void Produce(int count, int threadNum){
    prodTrack = (prodTrack + 1) % (bufferSize + 1); //I believe these should be the same algorithm for tracking the que rotation position
    int randomNumber = rand() % (11); //can be changed for true random up to you
    pthread_mutex_lock(&lock1);
    while(bufferSize == buffer.size()){
        cout << "P" << threadNum << ": Blocked due to full buffer" << endl;
        //cout << "Producer " << threadNum << " is waiting" << endl;
        pthread_cond_wait(&IS_FULL, &lock1);
    }
    //critical section
    cout << "P" << threadNum << ": Writing " << randomNumber << " to position " << prodTrack << endl;
    buffer.push(randomNumber);
    pthread_mutex_unlock(&lock1); //unlock the buffer
    pthread_cond_signal(&IS_FULL); //wake the threads that are waiting to access the buffer
    if(count == 0){
        cout << "P" << threadNum << ": Done waiting on full buffer" << endl;
        //cout << "producer x done producing" << endl;
    } else{
        Produce(count - 1, threadNum);
    }
    

}
void Consume(int count, int threadNum){
    qTrack = (qTrack + 1) % (bufferSize + 1); //for tracking the position that is being removed, although it actually just always removes from the front of the queue, it gives perception of the position it came from
    pthread_mutex_lock(&lock1);
    while (buffer.empty() == true) {
        pthread_cond_wait(&IS_EMPTY, &lock1);
        cout << "C" << threadNum << ": Blocked due to empty buffer" << endl;
        //cout << "Consumer x is waiting" << endl;
    }
    //critical section

    cout << "C" << threadNum << ": Reading " << buffer.front() << " from position " << qTrack << endl;

    buffer.pop();
    pthread_mutex_unlock(&lock1); //unlock the buffer
    pthread_cond_signal(&IS_EMPTY); //wake the threads that are waiting to access the buffer
    
    if (count == 0) {
        pthread_mutex_lock(&lock1);
        cout << "Consumer " << threadNum << " done consuming" << endl;
        pthread_mutex_unlock(&lock1);
    } else{
        Consume(count - 1, threadNum);
    }
}

