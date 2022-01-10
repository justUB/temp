/*
* Copyright: Vehant Technologies (P) Ltd			
*/

/*
* queue.h
* ------------------					
* This is a header file for queue class.				
*
* Initial Author: M Uday
*/


#include <stdlib.h>

struct node{            // Data node
    int val;
    node* next;

    node(int key){      // node constructor
        val = key;
        next = NULL;
    }
};

struct link             // Data structure for linking the nodes
{
    int length;
    node* head;
    node* tail;
    link* next;  //points to next list(queue)

    link(){                 // link constructor
        length = 0;             
        head = tail = NULL;
        next = NULL;
    }
    
    
};


class queue{
    link* front = new link(); //Head list
    link* rear = new link(); // Tail/last list

    void display();  // To display/print the queue
    public:
        void push(int &key);
        int pop(void);

};