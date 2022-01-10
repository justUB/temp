#include <../include/studentRecord.h>
#include <iostream>
#include <string>
using namespace std;

void studentRecord::addRecord(int &roll, string &(name)){       // to add entries to the data
    studentData temp;   // temporary entry node
    int flag = 0;
    for (std::list<studentData>::iterator it = data.begin(); it!= data.end();++it){
        if(it->roll == roll){   // checks if entry with given roll already exists.
            cout << "Entry with given roll already exists \n"<<"Name: "+it->name+" Roll: "<<it->roll<<endl;
            flag = 1;
        }
    }
    if(!flag){
        temp.name = name;       // if it doesn't exist, create the node
        temp.roll = roll;
        data.push_back(temp);   // adding to the data list
    }
}

void studentRecord::deleteRecord(int &roll, string &(name)){    // to delete an entry using roll and name
    list <studentData> temp ;   // temporary list
    int flag = 0;
    for (std::list<studentData>::iterator it = data.begin(); it != data.end(); ++it)
    {
        if((it->name == name) && (it->roll == roll)){
            continue;
            flag = 1;       // does nothing if the name and roll matches
        }
        else{               // else adds to the temp list
            studentData newN;
            newN.name = it->name;   
            newN.roll = it->roll; 
            temp.push_back(newN);
        }
    }
    data = temp;    // temp becomes the modified data list
    if (flag){
        cout << "Deletion successful"<<endl;
    }
    else{
        cout << "Given entry doesnot exist\n";
    }
    
}

void studentRecord::updateRecord(int &Oroll, int &Nroll, string &(Nname)){ // updates a given entry (oroll) with Nroll and Nname
    list <studentData> temp ; // temporary data list
    int flag=0; // to flag the existence of the matching entry
    for (std::list<studentData>::iterator it = data.begin(); it != data.end(); ++it)
    {
        if(it->roll == Oroll){
            it->name = Nname;           // if entry exists, change the name and roll
            it->roll = Nroll;
            flag = 1;
        }
        studentData newN;
        newN.name = it->name;
        newN.roll = it->roll; 
        temp.push_back(newN);       // push the nodes onto the temp list
    }
    data = temp;        // temp becomes the modified data list
    if (flag){
        cout << "Updation successful"<<endl;
    }
    else{
        cout << "Entry with given roll does not exist"<<endl;
    }
}

void studentRecord::displayRecords(){       // to display all records
    for (std::list<studentData>::iterator it = data.begin(); it != data.end(); ++it){
        cout<< "Name: "+it->name+", Roll: "<<it->roll<< endl;
    }
}

