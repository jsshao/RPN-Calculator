/*Jason Shao                ICS4U               November 20, 2011
Stack and RPN Class Implementations 
*/

#include <iostream>
#include <cmath>
#include "RPN_1.h"

using namespace std;

#define PI 3.1415926535897932384626433832795

Stack::Stack(){
     head = 0; //initializes the head pointer to create an empty linked list
}

Stack::~Stack(){
     //Deallocates all of the nodes created from memory
     NODE* node = head, *temp;
     
     while (node){ //traverse through list
          temp = node;
          node = node->next;
          delete temp; //deallocation
     }
}
    
void Stack::push(float number){
     //puts the number at the head of the list
     NODE *newNode;
     newNode = new NODE; //allocates new memory
     newNode->num = number; //assign value
     newNode->next = head; //store address of next node in the linked list
     head = newNode; //re-assign the head
}

float Stack::pop(){
    if (head){
       NODE* node = head; 
       float temp = head->num; //remembers value at the top of the linked list
       head = head->next; //re-assign head
       delete node; //deallocates memory of the node at the old head
       return temp;
    }
}

bool Stack::isEmpty(){
    return (!head); //determines whether the list is empty
}

void RPN::DisplayStack(){
    NODE*node = head;
    
    while (node){ //traverses through the list and outputs each data
          cout << node->num; 
          if (node == head)
              cout << " <-------- TOP"; //explicitly shows the value at the top
          cout << endl;
          node = node->next; //increment to next node
    }
    cout << endl << endl;
}

void RPN::add(){
    if (head==NULL || head->next == 0) //Error-checks for at least two nodes
       return;
       
    push(pop() + pop()); //sum of top 2 values
}

void RPN::subtract(){
    if (head==NULL || head->next == 0) //Error-checks for at least two nodes
       return;
       
    push((pop() - pop())*-1); //difference of top 2 values
}

void RPN::multiply(){
    if (head==NULL || head->next == 0) //Error-checks for at least two nodes
       return;
       
    push(pop()*pop()); //product of top 2 values
}

void RPN::divide(){
    if (head==NULL || head->next == 0) //Error-checks for at least two nodes
       return;  
       
    push(1./(float(pop())/pop())); //quotient of top 2 values
}

void RPN::factorial(){
    if (head==NULL) //Error-checks for at least one node
       return;
       
    float temp = 1;
    
    for (int i = pop(); i>0; i--) //convert the number into a integer
        temp*=i; //multiply until factorial is done
    push(temp); //factorial value
}     

void RPN::sine(){
     if (head==NULL) //Error-checks for at least one node
       return;
       
     push(sin(pop()*PI/180)); //convert to degrees and then push sine value
}
void RPN::cosine(){
     if (head==NULL) //Error-checks for at least one node
       return;
       
     push(cos(pop()*PI/180)); //convert to degrees and then push cosine value
}
void RPN::tangent(){
     if (head==NULL) //Error-checks for at least one node
       return;
       
     push(tan(pop()*PI/180)); //convert to degrees and then push tangent value
}
void RPN::log(){
     if (head==NULL) //Error-checks for at least one node
       return;
       
     push(log10(pop())); //convert to degrees and then push log value
}
