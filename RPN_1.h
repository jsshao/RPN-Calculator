/* Jason Shao               ICS4U                   November 20th, 2011
Stack Class and RPN Class */

#ifndef RPN_1
#define RPN_1

struct NODE{
        float num; //the value of the number that is stored into calculator
        NODE* next; //address of the next number in the stack
};

class Stack{
           protected:
              NODE* head; //pointer to the head of all nodes (top of the stack)
           public:
              Stack();  //constructor to initialize the head
              ~Stack(); //destructor
              
              //modifiers
              void push(float number); //function that pushes a value into the stack (allocates memory for newnode)
              float pop();  //deletes the value at the head and re-assign head
              
              //accessor method
              bool isEmpty(); //determines whether the list of nodes is empty
};

class RPN : public Stack{
      public:
             //display method
             void DisplayStack(); //outputs all values in the current stack
             
             //modifiers
             void add();          //pushes in sum of top 2 values
             void subtract();     //pushes in difference of top 2 values
             void multiply();     //pushes in product of top 2 values
             void divide();       //pushes in quotient of top 2 values
             void factorial();    //pushes in the factorial value of the top value
             void sine();         //pushes in the sin value of the top value
             void cosine();       //pushes in the cos value of the top value
             void tangent();      //pushes in the tan value of the top value
             void log();          //pushes in the logarithm of the top value
};

#endif
