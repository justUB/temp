#include "../include/ProducerConsumer.h"
#include <thread>

using namespace std;

int main(){
    ProducerConsumer pcobj;
    thread thread1(&ProducerConsumer::consumer,&pcobj);
    thread thread2(&ProducerConsumer::producer,&pcobj);
    thread1.join();
    thread2.join();
    return 0;
}