#include <../include/GenSort.h>
#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
using namespace std;


void GenSort::generaterandom(ofstream &inp){            // Generates random numbers into the input file passed.
    cout << "Generating the random sequence"<<endl;
    for (int i =0;i< Nums;i++){
        inp << rand()%Nums << endl;
    }
}

void GenSort::populate_sub(ifstream &inp){              // populating the sub list for storing a chunk.
    string a;
    int num;
    
    while(!inp.eof()){
        getline(inp,a);
        if(a!=""){
            stringstream tmp(a);     // to convert string a to int num
            tmp >> num;
            sub.push_back(num);      // pushing into sub
        }
    }
}

void GenSort::splitfiles(ifstream &inp){        // to split the total generated numbers into chunks that can be stored
    string a;
    int n = 0; // count
    ofstream tmp;
    int batch = 1;
    int num;
    cout << "Splitting the total data into chunks" << endl;
    while(!inp.eof()){  //reading input file(main file)
        getline(inp,a);
        if(a!=""){
            if (n%Buffer == 0){     // if count reaches buffer limit
                tmp.close();        // close current file
                ostringstream stm ;
                stm << batch ; 
                string name = "util/"+stm.str();
                tmp.open(name.c_str(),ios::out|ios::binary); // create file for next chunk.
                batch++;
            }

            stringstream temp(a);
            temp >> num;
            tmp << num <<endl; // writing to file
        }
        n++;
    }
}

void GenSort::sortbase(){       // to sort individual chunks
    ifstream tmp;
    cout << "Sorting individual chunks" << endl;
    for(int j = 1;j<=Batch;j++){
        ostringstream stm ;
        stm << j ; 
        string name = "util/"+stm.str();
        tmp.open(name.c_str(),ios::in|ios::binary);
        if (!tmp)               // checking if chunk file exists
            cout<<"Not exists";
        populate_sub(tmp);          // writing the data from input chunk file to sub
        ofstream wpoint("util/temp",ios::out|ios::binary);
        list <int> temp;      // for populating the sorted values  
        int n = sub.size();
        int i = 0;
        while( i < n){              // sorting using selection sort
            list<int>::iterator minptr = sub.begin();           // initializing iterator pointer
            int min = 99999;
            for (list<int>::iterator it = sub.begin(); it!= sub.end();++it){    
                if (*it<min)
                {
                    min = *it;
                    minptr = it;                    //Finding min value and its corresponding index from the list.
                }
            }
            sub.erase(minptr);   // removing the min from the list
            temp.push_back(min); // appending to sorted array
            wpoint << min << endl;  // writing to temp file
            ++i;
        }
        cout << "sorted file "<<name.c_str()<<endl;
        tmp.close();
        remove(name.c_str());           // removing existing chunk file
        wpoint.close();
        rename("util/temp",name.c_str());   // renaming temp file(sorted) to existing chunk file name.
    }
}

void GenSort::sortFinal(void){          // Finally merging all sorted chunks
    int n = 0;
    //populate_mat();
    ofstream wpoint;
    ifstream rpoint;
    ofstream fpoint("Sorted Main",ios::out|ios::binary);        // Final sorted file
    cout << "\nFinal sorted sequence will be saved in \'Sorted Main\'"<<endl;
    while(n<Nums){
        int min = 99999;                
        int minIdx = 0;
        for(int j = 1;j<=Batch;j++){    //loop over all chunk files
            ostringstream stm ;
            stm << j ; 
            string name = "util/"+stm.str();
            rpoint.open(name.c_str(),ios::in|ios::binary);  // opening the chunk file
            string a;
            int num;
            getline(rpoint,a);      // getting the first num
            if(a!=""){
                stringstream tmp(a);
                tmp >> num;
                if(num < min){
                    min = num;
                    minIdx = j;         // finding min first number among all existing sorted chunk files
                } 
            }
            
            rpoint.close();
        }
        ostringstream stm ;
        stm << minIdx;                  // storing name of chunk file of min first value
        string name = "util/"+stm.str();
        rpoint.open(name.c_str(),ios::in|ios::binary);  //opening chunk file of min first value
        wpoint.open("temp",ios::out|ios::binary);       // creating a temp file
        string a;
        getline(rpoint,a); // to get first line
        while(!rpoint.eof()){
            getline(rpoint,a);
            if (a!="")
                wpoint<<a<<endl;        // writing all except the first line to the temp file
        }
        rpoint.close();
        remove(name.c_str()); // removing the existing chunk file
        wpoint.close();
        rename("temp",name.c_str()); // renaming temp to the existing chunk file
        fpoint << min<<endl;
        n++;
        
    }
    fpoint.close();
    for (int i = 1;i<=Batch;i++){
        ostringstream stm ;
        stm << i ; 
        string name = "util/"+stm.str();        
        remove(name.c_str());               // Removing all chunk files after sorting completes
    }
    cout << "Sorting completed !"<< endl;
}