//
//  List.hpp
//  304HW5
//
//  Created by Daniel on 2020-04-08.
//  Copyright © 2020 Daniel. All rights reserved.
//

#ifndef List_hpp
#define List_hpp
#include <vector>
#include <iostream>

using namespace std;
#include <stdio.h>
class List{
public:
    List(int n){
        size = n;
        currSize = 0;
        numbers = new int[n];
    }
    List(){
    }
    bool compare(List others);
    void insert(int number);
    void display();
    int getElement(int i);
    
private:
        int size;
        int currSize;
        int *numbers;
};
    
#endif /* List_hpp */
