//cs 304 HW2
//Daniel Yi Hong
//student ID: 002244776

#include "Stack.hpp"
#include <vector>
#include <string>
#include <iostream>

#include <stdio.h>

using namespace std;


void Stack::push(string chars){
    charArray.push_back(chars);
}
void Stack::pop(){
    charArray.pop_back();
}
string Stack::top(){
    return charArray.back();
}

bool Stack::empty(){
    if (charArray.empty())
        return true;
    return false;
}
