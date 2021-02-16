//cs 304 HW2
//Daniel Yi Hong
//student ID: 002244776

#include <iostream>
#include "Expression.hpp"
#include <string>
#include <iostream>
#include <vector>

//this program doesn't have fancy features such as user input error detection.
int main (){
    //testing cases
    //string abc = "(5+3)*(8-2)";
    string abc = "a+b*c+(d*e+f)*g";
    Expression p1 (abc,1);
    cout<<p1.inToPost()<<endl;
    
    string cba = "abc*+de*f+g*+";
    Expression p2 (cba,2);
    cout<<p2.postToIn()<<endl;
    
    string numbers = "53+82-*";
    Expression p3 (numbers,2);
    cout<<p3.evaluate()<<endl;
    //user cases
    string userinput;
    int direction;
    cout<<"input a string, for infix, it looks like a+b*c+(d*e+f)*g or (5+3)*(8-2), if console gives you an auto ')', you have to type it again in order to register it into input. \nFor post fix, it looks like abc*+de*f+g*+ or 53+82-*. \nno space needed in the string, for evaluation, it must be in digits format: "<<endl;
    cin>>userinput;
    cout<<"if its infix, enter 1; if its postfix, enter 2: "<<endl;
    cin>>direction;
    Expression p4 (userinput,direction);
    if (direction == 1){
        cout<<"post fix is: "<<p4.inToPost()<<endl;
        //convert to postfix first before evaluation
        string A = p4.inToPost();
        Expression p5 (A,2);
        cout<<"evaluation is: "<<p5.evaluate()<<endl;
    }
    else if (direction == 2){
        cout<<"post fix is: "<<p4.postToIn()<<endl;
        cout<<"evaluation is: "<<p4.evaluate()<<endl;
    }
    
}

