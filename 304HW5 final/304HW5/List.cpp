//cs 304 HW5
//Daniel Yi Hong
//student ID: 002244776
//

#include "List.hpp"
#include <vector>
#include <iostream>

using namespace std;

    void List::insert(int number){
        numbers[currSize++] = number;
    }
    bool List::compare(List others){
        for (int i=0; i<size; i++){
            if (numbers[i] != others.numbers[i])
                return false;
        }
        return true;
    }
    
    void List::display(){
        if (currSize==0) return;
        for (int i=0; i<size; i++){
            cout<<numbers[i]<<" ";
        }
    }
    int List::getElement(int i){
        return numbers[i];
    }
    
