#include "../include/queue.h"
#include <iostream>
using namespace std;

int main(){
    queue q;
    int a = 1;
    for(int i = 1; i<=11;i++){
        q.push(i);
    }
    for(int i = 1; i<=12;i++){
        q.pop();
    }
    a = 12;
    q.push(a);
}

