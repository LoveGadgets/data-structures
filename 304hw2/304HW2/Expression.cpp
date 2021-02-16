//cs 304 HW2
//Daniel Yi Hong
//student ID: 002244776

#include "Expression.hpp"
#include <string>
#include <iostream>
#include <vector>
#include "Stack.hpp"

using namespace std;

//find operator
bool isOperator(string currentChar) {
   if (currentChar == "+" || currentChar == "-" || currentChar == "*" || currentChar == "/") {
       return true;}
    return false;
}
//find operand
bool isOperand(string currentChar) {
    if (!isOperator(currentChar) && currentChar != "(" && currentChar != ")") {
        return true;
    }
    else return false;
}
//compare priority of operator
int compareOperators(string operator1, string operator2) {
    if ((operator1 == "*" || operator1 == "/") && (operator2 == "+" || operator2 == "-")) { return -1;
    }
    else if ((operator1 == "+" || operator1 == "-") && (operator2 == "*" || operator2 == "/")) {
        return 1;
    }
    else return 0;
}
double operate(string a, string b, string c){
    //convert string to double
    double A = stod(a);
    double B = stod(b);
    //cout<< A<<endl;
    //cout<< B<<endl;
    //operate oprands base on different operators
    if (c == "+")
        return A+B;
    else if(c == "-")
       return A-B;
    else if(c == "*")
       return A*B;
    else if(c == "/")
       return A/B;
    else
    return 0;
}


string Expression::inToPost() {
    string postfixString = "";
    vector<string> postfixStack;
    Stack p1 (postfixStack);
    
    /* another method using char. I use string in this program for simplicity.
     char charOfString[100];
    vector<char> chars;
    convert input string to char array
    for (int i = 0; i<infix.length(); i++){
       // chars.push_back(infix[i]);}*/
    for (int i = 0; i< infix.size(); i++){
        if (isOperand(infix.substr(i,1))) {
            postfixString.push_back(infix[i]);
        }
        else if (isOperator(infix.substr(i,1))){
            /*Pop until the top of the stack has an element of lower
            precedence, Then push current char
            */
            while (!p1.empty() && p1.top() != "(" && compareOperators(p1.top(),infix.substr(i,1)) <= 0)   {
                postfixString += p1.top();
                p1.pop();
                }
            //put current operator on stack
            p1.push(infix.substr(i,1));
            }
        //if (, put it to stack
        else if (infix.substr(i,1) == "(") {
            p1.push(infix.substr(i,1));
        }
        else if (infix.substr(i,1) == ")") {
            /*When ) is found, pop until the matching ( */
            while (!p1.empty()) {
                if (p1.top() == "(") {
                    p1.pop(); break;
                }
                postfixString += p1.top();
                p1.pop();
            }
        }
    }
    //for remainder of stack, add top element to string then pop it, repeat until empty stack
    while (!p1.empty()) {
        postfixString += p1.top();
        p1.pop();
    }
    return postfixString;
}

string Expression::postToIn() {
    //string infixString = "";
    vector<string> infixStack;
    Stack p2 (infixStack);
    
    for (int i = 0; i< postfix.size(); i++){
        if (isOperand(postfix.substr(i,1))) {
            p2.push(postfix.substr(i,1));
        }
        else{
            string operand1 = p2.top();
            //cout<<p2.top();
            p2.pop();
            string operand2 = p2.top();
            //cout<<p2.top();
            p2.pop();
            p2.push("(" + operand2 +  postfix.substr(i,1) + operand1 + ")");
        }
    }
    return p2.top();
}


double Expression::evaluate() {
    vector<string> evaluateStack;
    Stack p3 (evaluateStack);
    for (int i = 0; i< postfix.size(); i++){
        if(isOperand(postfix.substr(i,1))){
            p3.push(postfix.substr(i,1));
        }
        else if(isOperator(postfix.substr(i,1))) {
            string a = p3.top();
            p3.pop();
            string b = p3.top();
            p3.pop();
            //cout<<operate(a,b,postfix.substr(i,1))*-1;
            //operate two operands and string casting the return value, and
            //put it into the stack.
            string c = to_string(operate(b,a,postfix.substr(i,1)));
            p3.push(c);
            }
    }
    //the last value on stack is the result.
    return stod(p3.top());
}





    



    
