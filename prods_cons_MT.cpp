//
//  prods_cons_MTT.cpp
//  remakeeeee
//
//  Created by Danny Webb-McClain on 3/22/22.
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
extern pthread_mutex_t lock1;
extern queue<int> buffer;
extern int bufferSize, pThread, cThread, qTrack, prodTrack, extraConsume;
extern bool specialConsumer;

void Produce(int count, int threadNum){
    prodTrack = (prodTrack + 1) % (bufferSize + 1); //I believe these should be the same algorithm for tracking the que rotation position
    int randomNumber = rand() % (11); //can be changed for true random up to you
    pthread_mutex_lock(&lock1);
    while(bufferSize == buffer.size()){
        cout << "Producer " << threadNum << " is waiting" << endl;
        pthread_cond_wait(&IS_FULL, &lock1);
    }
    //critical section
    cout << "P" << threadNum << ": Writing " << randomNumber << " to position " << prodTrack << endl;
    buffer.push(randomNumber);
    pthread_mutex_unlock(&lock1); //unlock the buffer
    pthread_cond_signal(&IS_FULL); //wake the producers that queue is no longer full
    if(count == 0){
        cout << "producer x done producing" << endl;
    } else{
        Produce(count - 1, threadNum);
    }
    

}
void Consume(int count, int threadNum){
    qTrack = (qTrack + 1) % (bufferSize + 1); //for tracking the position that is being removed, although it actually just always removes from the front of the queue, it gives perception of the position it came from
    pthread_mutex_lock(&lock1);
    while (buffer.empty() == true) {
        pthread_cond_wait(&IS_EMPTY, &lock1);
        cout << "Consumer x is waiting" << endl;
    }
    //critical section
    cout << "C" << threadNum << ": Reading " << buffer.front() << " from position " << qTrack << endl;
    buffer.pop();
    pthread_mutex_unlock(&lock1); //unlock the buffer
    //Wake the consumers that have been set to sleep over empty queue
    pthread_cond_signal(&IS_EMPTY);
    if (count == 0) {
        cout << "Consumer " << threadNum << " done consuming" << endl;
    } else{
        Consume(count - 1, threadNum);
    }
}

