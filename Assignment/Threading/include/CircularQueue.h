#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

using namespace std;

class CircularQueue{
    int rear,front;
    int size;
    int *arr;

    public:
        CircularQueue(int s);
        void enqueue(int &key);
        int dequeue();
};

#endif