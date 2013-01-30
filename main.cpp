/*Jason Shao                    ICS4U                       November 20, 2011
This program declares a calculator using the RPN class which inherits the Stack class. It stores
numbers that are user-inputted into a dynamic linked list. It can perform operations of addition/subtraction/
multiplication/division. It then displays the up-to-date values within the calculator memory.
Error checking for invalid inputs is done and such inputs are ignored. 
*/

#include <iostream>
#include <string>
#include <windows.h>
#include "RPN_1.h"
#include "RPN_1.cpp"

using namespace std;

bool isNum(string input); //Determines whether the input is valid (numeric)

int main(){
    //Declaration and Initializations
    RPN Calc;
    string Input = "";
    
    //Calculator continues to read inputs until the user inputs 'q' to quit.
    while (Input.compare("q")){
          //Instructions and Input
          cout << "          Please input number, operation (+ - * /), trig (sin/cos/tan)," <<endl <<endl 
               << "                   log (base 10), factorial(!), clear, quit(q): " << endl << endl
               << "                                       ";
          cin >> Input;
          
          //Process: Perform appropriate operations: 
          //add; subtract; multiply; divide; trig; log; clear screen; store number
          if (Input == "+")
             Calc.add();
          else if (Input == "-")
             Calc.subtract();
          else if (Input == "*")
             Calc.multiply();
          else if (Input == "/")
             Calc.divide();
          else if (Input == "!")
             Calc.factorial();
          else if (Input == "sin")
             Calc.sine();
          else if (Input == "cos")
             Calc.cosine();
          else if (Input == "tan")
             Calc.tangent();
          else if (Input == "log")
             Calc.log();
          else if (Input == "clear"){
               while(!(Calc.isEmpty())) //Deletes all inputs in memory until the list of numbers is empty
                    Calc.pop();
          }
          else if (isNum(Input))
             Calc.push(atof(Input.c_str())); //Pushes the float value of number into the stack
          else {              
             if (Input!="q"){ //Any other input except for 'q' is an invalid input at this point
                cout << "                                INVALID INPUT!!!!";
                Sleep(1000);
             }
          }
             
          system("cls"); //clear screen
          
          //Output: Unless the stack is empty, Output all the current values in the stack
          if (!Calc.isEmpty())
             Calc.DisplayStack();
             
    }   
    return 0;
}

//Error checks the string input to make sure the user is attempting to input a number
bool isNum(string input){
    for (int i = 0; i < input.length(); i++){
        if (!(isdigit(input[i])) && input[i] != '.' && input[i] != '-') //if the digit is a number, decimal, or negative sign.
             return 0;
    }
    return 1; //all digits are numbers or decimal/negative
}
