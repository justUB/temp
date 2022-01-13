#include "../include/CircularQueue.h"
#include <iostream>

using namespace std;

CircularQueue::CircularQueue(int s){
    size = s;
    front = rear = -1;
    arr = new int [s];
}

void CircularQueue::enqueue(int &key){
    while ((front == 0 && rear == size-1)||(rear==(front-1)%(size-1))){

    }
    if (front=-1){
        front = rear = 0;
        arr[rear] = key;
    }
 
    else if (rear == size-1 && front != 0)
    {
        rear = 0;
        arr[rear] = key;
    }
 
    else
    {
        rear++;
        arr[rear] = key;
    }
}

int CircularQueue::dequeue(){
    while (front == -1)
    {

    }
    //cout <<"Done "; 
 
    int data = arr[front];
    arr[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size-1)
        front = 0;
    else
        front++;
 
    return data;
}