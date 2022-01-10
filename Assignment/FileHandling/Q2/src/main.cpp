#include "../include/GenSort.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    GenSort obj;
    ifstream rpoint("Main", ios::in|ios::binary);       // opening main file containing the generated nmbers
    if(!rpoint){    // checking if it doesnot exist
        ofstream wpoint("Main", ios::out|ios::binary);  // creating main file
        obj.generaterandom(wpoint);         //generating numbers to main file
        wpoint.close();
        rpoint.open("Main", ios::in|ios::binary); // read pointer to main file
        obj.splitfiles(rpoint);     // splitting to chunks
        obj.sortbase();         // sorting chunks
        obj.sortFinal();        // merging sorted chunks
    }
    else{
        obj.splitfiles(rpoint);
        obj.sortbase();
        obj.sortFinal();
    }
    return 0;
}