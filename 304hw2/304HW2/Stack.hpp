//cs 304 HW2
//Daniel Yi Hong
//student ID: 002244776

#ifndef Stack_hpp
#define Stack_hpp

#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

class Stack {
public:
    //constructor
    Stack(vector<string> chars){
        charArray = chars;
    }
    //method
    void push(string chars);
    
    void pop();

    //string peek();
    
    string top();
    
    bool empty();

private:
    vector<string> charArray;
};

#endif /* Stack_hpp */

