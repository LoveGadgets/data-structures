//cs 304 HW1
//Daniel Yi Hong
//student ID: 002244776


#include "polynomials.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

vector<double> polynomials::add(polynomials external) {
    vector<double> newCoef;
    int sizeScope = static_cast<int>(coef.size());
    int sizeExternal =  static_cast<int>(external.coef.size());
    int biggerSize;
    if (sizeScope >= sizeExternal){
        biggerSize = sizeScope;
    }
    else {
        biggerSize = sizeExternal;
    }
    //cout<<biggerSize;
    //add two arrays and put sum into the new array, if the i is
    //larger than any one array, then put the value from the other array
    //directly into array
    for (int i = 0; i< biggerSize; i++){
        if (i>sizeScope-1){
            newCoef.push_back(external.coef[i]);
        }
        else if (i>sizeExternal-1){
            newCoef.push_back(coef[i]);
            //cout<< coef[i]<<endl;
        }
        //cout << coef[i] <<endl;
        else {
            newCoef.push_back(coef[i]+external.coef[i]);
        }
    }
    return newCoef;
}
//subtract two arrays and put subtraction into the new array, if the i is
//larger than any one array, then put the value * (-1) directly into array
vector<double> polynomials::subtract(polynomials external) {
    vector<double> newCoef;
    int sizeScope = static_cast<int>(coef.size());
    int sizeExternal =  static_cast<int>(external.coef.size());
    int biggerSize;
    if (sizeScope >= sizeExternal){
        biggerSize = sizeScope;
    }
    else {
        biggerSize = sizeExternal;
    }
    for (int i = 0; i< biggerSize; i++){
        if (i>sizeScope-1){
            newCoef.push_back((external.coef.at(i))*(-1));
        }
        else if (i>sizeExternal-1){
            newCoef.push_back(coef.at(i));
        }
        else {
            newCoef.push_back(coef.at(i)-external.coef.at(i));
        }
    }
    return newCoef;
}

vector<double> polynomials::multiply(polynomials external) {
    vector<double> newCoef;
    int sizeScope = static_cast<int>(coef.size());
    int sizeExternal =  static_cast<int>(external.coef.size());
    for (int i = 0; i < (sizeScope+sizeExternal-1); i++){
        newCoef.push_back(0);
    }
    //this method will let all coefficients that have same power of x
    //add together and put into new array in the corrent order
    for (int i = 0; i< sizeScope; i++){
        for (int j=0; j<sizeExternal; j++){
            newCoef[i+j] += coef[i]*(external.coef[j]);
        }
    }
    return newCoef;
}

double polynomials::evaluate(double x){
    double sum = coef[0];
    int sizeScope = static_cast<int>(coef.size());
    for (int i=1; i < sizeScope; i++){
        sum+=coef[i]*pow(x,i);
    }
    return sum;
}

void polynomials::findRoots(){
    int sizeScope = static_cast<int>(coef.size());
    //cout << sizeScope;
    double root1 = NULL;
    double root2 = NULL;
    if (sizeScope >3) cout<<"cannot find root because degree is larger than 2"<<endl;
    else{
        //using math equations to find root
        double discriminant = pow((coef[1]),2) - 4*coef[0]*coef[2];
        if (discriminant == 0){
            root1 = -coef[1]/(2*coef[0]);
            root2 = root1;
        }
        else if (discriminant > 0){
            root1 = (-coef[1] + sqrt(discriminant))/(2*coef[0]);
            root2 = (-coef[1] - sqrt(discriminant))/(2*coef[0]);
        }
        else if (discriminant < 0){
            cout<<"no root";
        }
        cout<<"\nroot 1 is "<<root1<<endl;
        cout<<"root 2 is "<<root2<<endl<<endl;
     }
}


void polynomials::display(){
    int size = static_cast<int>(coef.size());
    for (int i = 0; i< size; i++){
        if (coef[i]!=0){
            cout << coef[i];
        if (i == 1)
          cout << "x";
        if (i >= 2)
         cout << "x^" << i ;
        if (i != size-1)
        cout << " + ";
    }
    }
}
