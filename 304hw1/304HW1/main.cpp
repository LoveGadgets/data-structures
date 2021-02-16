//cs 304 HW1
//Daniel Yi Hong
//student ID: 002244776


#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "polynomials.hpp"
using namespace std;

int main (){
    vector<double> array1 = {5, 0, 3.5, 16, -2};
    vector<double> array2 = {1, -2, 0.5};
    vector<double> array3 = {1, -2};
    polynomials P1 (array1);
    polynomials P2 (array3);
    polynomials newP = P1.add (P2);
    //newP.display();
    polynomials newP2 = P1.subtract (P2);
    polynomials newP3 = P1.multiply(P2);
    P1.display();
    cout<<"\nevaluation is "<<newP3.evaluate(2)<<endl;
    cout << "the value of the polynomial is " << newP3.evaluate(2) << endl;
    P1.findRoots();



    
}
