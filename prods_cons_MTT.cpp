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
extern pthread_cond_t NAME;
extern pthread_mutex_t lock1;
extern vector<int> buffer;
extern int bufferSize, pThread, cThread;
void Produce(int count){ //I think we need to pass the thread ID here for printing purposes
    int randomNumber = rand() % (11);
    pthread_mutex_lock(&lock1);
    while(bufferSize == buffer.size()){
        cout << "Producer is waiting" << endl;
        pthread_cond_wait(&NAME, &lock1);
    }
    //critical section
    buffer.push_back(randomNumber);
    pthread_mutex_unlock(&lock1); //unlock the buffer
    pthread_cond_signal(&NAME); //wake the threads that are waiting to access the buffer
    if(count == 0){
        cout << "producer x done producing" << endl;
    } else{
        Produce(count - 1);
    }
    

}
void Consume(){
    pthread_mutex_lock(&lock1);
    while (buffer.empty() == true) {
        pthread_cond_wait(&NAME, &lock1);
    }
    //critical section
    pthread_mutex_unlock(&lock1);
}
