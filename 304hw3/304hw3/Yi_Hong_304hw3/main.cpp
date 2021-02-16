//cs 304 HW3
//Daniel Yi Hong
//student ID: 002244776

#include <iostream>
#include "LinkedList.cpp"


int main(int argc, const char * argv[]) {
    // insert code here...
    
    LinkedList theList;
    theList.insertFirst(44);
    theList.insertFirst(88);
    theList.insertFirst(66);
    theList.insertFirst(22);
    theList.insertFirst(55);
    theList.insertFirst(11);
    theList.insertFirst(33);
    theList.insertFirst(99);
    theList.display();
    theList.mergesort();
    theList.display();
    return 0;
}
