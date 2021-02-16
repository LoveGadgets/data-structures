//cs 304 HW4
//Daniel Yi Hong
//student ID: 002244776

#include <iostream>
#include <string>
#include "Trees.cpp"

using namespace std;

int main(int argc, const char * argv[]) {

    string prefixExpression1 = "+23";
    string prefixExpression2 = "-+231";
    string prefixExpression3 = "-4+23";
    string prefixExpression4 = "*+51-24";
    string prefixExpression5 = "/*+914+53";
    
    //change different expressions for testing
    Trees p1(prefixExpression1);
//
//    cout<<"prefix: ";
//    p1.printPrefix(p1.root);
//    cout<<endl;
//    p1.count();
    //cout<<p1.numLeaves;
//    cout<<endl;
//    p1.getInfix(p1.root);
//    cout<<"infix: "<<p1.printInfix();
//    cout<<endl;
//    void printInfix(Node* root){
//        if (root == NULL) {
//            return;
//        }
//        else {
//            printInfix(root->left);
//            cout<<root->value;
//            printInfix(root->right);
//
//        }
//    }
    
    int i = 5;
    int *p = NULL;
    int *q = NULL;
     p=&i;
p=*&i;
p=&*i;
         i=*&*p;
i=*&p;
i=&*p;
          p=&*&i;
q=*&*p;
q=**&p;
    q=*&p;
    q=&*p;
    cout <<p;

}
