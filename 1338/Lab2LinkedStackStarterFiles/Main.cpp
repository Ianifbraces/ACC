/* 
-------------------------------------------------------------------------
Name:     		Ian Korrub
Date: 			6/22
Lab #:     		2
Status: 		Submited
Class:			COSC 1338
-------------------------------------------------------------------------
Objectives: You will write a program to evaluate and display a prefix expression using a stack, not recursion.

-------------------------------------------------------------------------
*/

#include <iostream>				// for cin, cout, endl
#include <iomanip>
#include <string>
#include <ctime>
#include <cctype> 				// for toupper()
#include <cstdlib> 				// for random numbers
#include <fstream>              // filestream header
#include <cmath>
#include "LinkedStack.h"
using namespace std;

int main(){
    string expression;
    LinkedStack<int> stack;
    cout << "enter prefix expresion: ";
    cin >> expression; // gets expresion
    int num1;
    int num2;
    for(int i=expression.length()-1; i>=0; i--){//goes backwards, turning it into a postfix expesion
        if(expression[i] == '+'||expression[i] == '-'||expression[i] == '*'||expression[i] == '/'){
            num1 = stack.peek();
            stack.pop();// these are the two numbers the get operated on, put here because it saves me from having to copy paste it on 4 different spots
            num2 = stack.peek();
            stack.pop();// their removed from the stack, so another number can take their place.
            if (expression[i] == '+'){
                stack.push(num2 + num1);
            }
            else if (expression[i] == '-'){
                stack.push(num1 - num2);
            }
            else if (expression[i] == '*'){
                //stack.pop() << '*' << stack.peek() << ' ';
                stack.push(num2 * num1);
            }
            else if (expression[i] == '/'){
                stack.push(num1 / num2);
            }//these else ifs find which operation to use. inside them, they take the previos two integers, and appends them after the operation
        }
        else{
            if (expression[i] == '1'){
                stack.push(1);
            }
            else if (expression[i] == '2'){
                stack.push(2);
            }
            else if (expression[i] == '3'){
                stack.push(3);
            }
            else if (expression[i] == '4'){
                stack.push(4);
            }
            else if (expression[i] == '5'){
                stack.push(5);
            }
            else if (expression[i] == '6'){
                stack.push(6);
            }
            else if (expression[i] == '7'){
                stack.push(7);
            }
            else if (expression[i] == '8'){
                stack.push(8);
            }
            else if (expression[i] == '9'){
                stack.push(9);
            }
            else if (expression[i] == '0'){
                stack.push(0);
            }// finds what number is used, and puts it inside the stack as an int
        }// if there is just a number, add it to the stack
    }//end of for loop
    int result = stack.peek();
    stack.pop();
    cout << "The answer to the expresion is " << result; // displays the answer
    return 0;
}//end of Main