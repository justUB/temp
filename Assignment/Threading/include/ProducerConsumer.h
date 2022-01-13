#ifndef PRODUCERCONSUMER_H
#define PRODUCERCONSUMER_H
#define TOTALITEMS 100
#define BUFFER 5

#include <mutex>
#include <condition_variable>
#include <list>
#include "CircularQueue.h"

using namespace std;

class ProducerConsumer{
    mutex m_mutex;
    //list<int> queue;
    unique_ptr <CircularQueue> queue;
    bool m_flag;
    condition_variable condVar;
    public:
        ProducerConsumer();
        void producer();
        void consumer();
        int ProductionFlag();
};

#endif