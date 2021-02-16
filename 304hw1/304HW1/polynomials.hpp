//cs 304 HW1
//Daniel Yi Hong
//student ID: 002244776

#ifndef polynomials_hpp
#define polynomials_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class polynomials{
public:
    //constructor
    polynomials(vector<double> output):coef{output}{};
    vector<double> add(polynomials);
    vector<double> subtract(polynomials);
    vector<double> multiply(polynomials);
    double evaluate(double x);
    void findRoots();
    void display();
    
private:
    vector<double> coef;
    
};
    
#endif /* polynomials_hpp */
