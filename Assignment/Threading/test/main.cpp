#include "../include/ProducerConsumer.h"
#include <thread>

using namespace std;

int main(){
    ProducerConsumer pcobj;
    thread thread1(&ProducerConsumer::producer,&pcobj);
    thread thread2(&ProducerConsumer::consumer,&pcobj);
    thread2.join();
    thread1.join();
    return 0;
}