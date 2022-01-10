
#include "../include/studentRecord.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main(){
    studentRecord sdata;        //initializing object
    string name;
    int roll;
    cout << "Student Record Management Tool"<<endl;
    ifstream rpoint("record",ios::in|ios::binary);  //opening record file
    ofstream wpoint;
    if (!rpoint){    // checking if it exists
        fstream st; //Creating object of fstream class
        st.open("record",ios::out|ios::binary); // creating record file

        if(!st){                    // checking if its created
            cout <<"Not created";
        }
        else{
            cout << "Record created\nEnter the student details(in this format, name,roll)\n";
            string a;
            cin >> a;       // input in the form name,roll.
            name = a.substr(0,a.find(','));
            stringstream tmp(a.substr(a.find(',')+1));
            tmp >> roll;
            st << name<<','<<roll<<endl; //writing the entry to the record file.
            st.close();
        }
        
    }
    rpoint.open("record",ios::in|ios::binary);
    wpoint.open("temp",ios::out|ios::binary); 
    while(!rpoint.eof()){
        string a;   
        getline(rpoint,a);// to read the lines from the file
        if (a!=""){
            name = a.substr(0,a.find(','));
            stringstream tmp(a.substr(a.find(',')+1));
            tmp >> roll;
            sdata.addRecord(roll,name);     // populating the list by reading from the file.
        }
    }
    int choice;
    while(choice!=5){ // loop to allow user to choose required function, exit on choosing 5
        cout << "\n1-add record, 2-Delete record, 3-update record, 4-display records, 5-exit"<<endl;
        cout << "Enter your choice\n";
        int oroll; // for storing old roll for updating existing entry
        string inp;
        cin >> choice; // taking user choice
        switch (choice)
        {
        case 1:     // if choice is 1, add record is called
            cout <<"To add entry, enter details:\n";
            cout <<"Name: ";
            getline(std::cin>> std::ws, name);
            cout <<"Roll: ";
            cin >> roll;
            cout<< "Adding the entry\n";
            sdata.addRecord(roll,name);
            
            break;
        
        case 2:     // if choice is 2, delete record is called
            cout <<"To delete entry, enter details:\n";
            cout <<"Name: ";
            getline(std::cin>> std::ws, name);
            cout <<"Roll: ";
            cin >> roll;
            sdata.deleteRecord(roll,name);
            break;
        
        case 3:     // if choice is 3, update record is called
            cout <<"To update entry, enter the roll of entry to modify:\n";
            cin>>oroll;
            cout << "Enter new details:\n";
            cout <<"Name: ";
            getline(std::cin>> std::ws, name);
            cout <<"Roll: ";
            cin >> roll;
            sdata.updateRecord(oroll,roll,name);
            break;
        
        case 4:     // if choice is 4, display record is called
            cout << "Displaying all entries: \n";
            sdata.displayRecords();
            break;
        
        case 5:
            break;
        }
    }

    

    for (std::list<studentData>::iterator it1 = sdata.data.begin(); it1 != sdata.data.end(); ++it1)
    {
        wpoint << it1->name<<','<<it1->roll<<endl;          // Writing the final record data to temp file
    }
    rpoint.close();
    remove("record");       // removing existing record file
    wpoint.close();
    rename("temp","record"); // renaming temp file to record.
    return 0;
}