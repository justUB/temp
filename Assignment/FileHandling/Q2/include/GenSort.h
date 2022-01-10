/*
* Copyright: Vehant Technologies (P) Ltd			
*/

/*
* myclass.h
* ------------------					
* This is a header file for "myclass" class, contains functions for generating and sorting numbers.				
*
* Initial Author: M Uday
*/


#include <list>
#include <fstream>
#include <array>
using namespace std;

#define Nums 10000       // Total no. of numbers to be generated
#define Buffer 1000      // memory limit
#define Batch Nums/Buffer   // No. of chunks to be split into

class GenSort{
    public:
        list <int> sub;         // sub array for temporarily storing a chunk
        void generaterandom(ofstream &inp);
        void populate_sub(ifstream &inp);
        void splitfiles(ifstream &inp);
        void sortbase();
        void sortFinal(void);
};