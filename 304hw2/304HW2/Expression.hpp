//cs 304 HW2
//Daniel Yi Hong
//student ID: 002244776

#ifndef Expression_hpp
#define Expression_hpp

#include <stdio.h>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>


using namespace std;

class Expression {
    public:
//constructor
    Expression(string input, int direction) {
        if (direction == 1){
            infix = input;
        }
        else if(direction == 2){
            postfix = input;
        }
    }
//method
    string inToPost();
    string postToIn();
    double evaluate();
private:
    string infix;
    string postfix;

};
#endif /* Expression_hpp */
