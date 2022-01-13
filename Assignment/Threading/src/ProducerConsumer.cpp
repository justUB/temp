#include "../include/ProducerConsumer.h"
#include <random>
#include <fstream>
#include <thread>
#include <iostream>

using namespace std;

ProducerConsumer::ProducerConsumer(){
    int size = 5;
    queue = unique_ptr <CircularQueue> (new CircularQueue(size));
    m_flag = true;
}


void ProducerConsumer::producer(){
    //this_thread::sleep_for(std::chrono::milliseconds(1000));
    ofstream writePtr("producer",ios::out|ios::binary);
    int value;
    m_flag = true;
    for (int i=0;i<TOTALITEMS;i++){
        value = rand()%TOTALITEMS;
        //std::cout<<queue.size()<<endl;
        writePtr<<value<<endl;
        queue->enqueue(value);
    } 
    writePtr.close();
    lock_guard<mutex> guard(m_mutex);
    m_flag = false;
    condVar.notify_one();
}

int ProducerConsumer::ProductionFlag(){
    return m_flag;
}

void ProducerConsumer::consumer(){
    ofstream writePtr("consumer",ios::out|ios::binary);
    int value;
    for (int i=0;i<TOTALITEMS;i++){
        unique_lock<mutex> mlock(m_mutex);
        condVar.wait(mlock,bind(&ProductionFlag,this));

        if(m_flag){
            value = queue->dequeue();
            writePtr << value << endl;
        }
        
    }
    writePtr.close();
}