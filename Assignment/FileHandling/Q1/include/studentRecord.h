/*
* Copyright: Vehant Technologies (P) Ltd			
*/

/*
* studentRecord.h
* ------------------					
* This is a header file for studentRecord class.				
*
* Initial Author: M Uday
*/



#include <iostream>
#include <list>

using namespace std;

struct studentData{         // data structure for student data
    string name;
    int roll;
};

class studentRecord{
    public:
        std::list <studentData> data;   // stores all the entries.
        void addRecord(int &roll, string &(name));
        void deleteRecord(int &roll, string &(name));
        void updateRecord(int &Oroll, int &Nroll, string &(Nname));
        void displayRecords(void);

};