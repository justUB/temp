#include "../include/queue.h"
#include <iostream>

using namespace std;

void queue::display(){
    node* tmp;  
    link* Nlist; //List pointer to traverse through the queues
    Nlist = front; 
    int c = 0;

    while(Nlist){
        tmp = Nlist->head;
        while(tmp){
            cout<< "->"<< tmp->val ;
            tmp = tmp->next;
            c+=1;
        }
        cout << endl;
        Nlist = Nlist->next;
    }
    if (c!=0)
        cout << endl;
    else    
        cout << "The Queue is empty\n\n";
    
}


void queue::push(int &key){
    node* temp = new node(key);
    link *NList = new link();
    if(front->next == NULL){        // checking if queue has only one list.
        if(front->head==NULL){      // checking if queue exists, if not exists, creating one.
            front->head = front->tail = temp;
            front->length += 1;
        }
        else{
            if (front->length<5){       
                front->tail->next = temp;       //if length of list is <5, adding a new node to the tail
                front->tail = temp;
                front->length += 1;
            }
            else{
                NList->head = NList->tail = temp;
                NList->length += 1;                 // else adding the value to new list, and attaching to prev list.
                front->next = NList;
                rear = front->next;
            }
        }
    }
    else{                                            // If there are more lists in the queue
        if(rear->length<5){                          // and if length of the end list is <5 , adding
            rear->tail->next = temp;                 // to the rear.
            rear->tail = temp;
            rear->length += 1;
        }
        else{
            NList->head = NList->tail = temp;          // else creating new list and 
            NList->length += 1;                         // changing the rear pointer.
            rear->next = NList;
            rear = NList;
        }
    }
    cout<<"After pushing "<<key<<"\n";
    display();
}


int queue::pop(){
    int ret;
    link *tmp1 = new link();
    if(front->head == NULL){
        cout << "Nothing to pop!"<<endl;        // if queue is empty
    }
    else{
        ret = front->head->val;
        node* temp = front->head;                   // changing the head pointer of front list
        link *NList = new link();                   // to next node of the head.
        front->head = front->head->next;        
        delete [] temp;
        NList = front;
        
        if(front->next != NULL){
            while(NList->next!=NULL){
                link* tmp2 = NList->next;               // reording the entire queue by pushing the head 
                temp = new node(tmp2->head->val);       // node of each list to their previous lists.
                NList->tail->next = temp;
                NList->tail = temp;
                tmp2->head = tmp2->head->next;
                
                tmp1 = NList;
                NList = tmp2;
                if(tmp2->next == NULL){             
                    NList->length -= 1;
                    break;
                }
                

            }
            
            if(NList->length == 0){
                rear = tmp1;                //changing rear pointer to prev list if it becomes empty.
                rear->next = NULL;
            }


        }
        cout<<"After poppin "<<ret<<"\n";
        display();
    }
    return ret;
}