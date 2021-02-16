//cs 304 HW4
//Daniel Yi Hong
//student ID: 002244776

#include <string>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;


class Trees{
    //inner node class to build nodes
    class Node{
    private:
        Node(){
            left = nullptr;
            right = nullptr;
        }
    private:
        string value;
        Node *left;
        Node *right;
        friend class Trees;
    };
    

public:
    //root node of the tree that was built
    Node* root;
    //constructor
    Trees(string input){
        for (int i = 0; i<input.length(); i++){
            //add each char of the expression to a queue
            prefix_input.push(input.substr(i,1));
        }
        //build the tree and assign the root node
        root = insert(prefix_input);
    }
    //testing if the char is operator
    bool isOperator(string currentChar){
        if (currentChar == "+" ||currentChar == "-" ||
            currentChar == "*" ||currentChar == "/" ){
            return true;}
        return false;
    }
    bool isOperand(string currChar){
        if (!isOperator(currChar) && currChar!="(" && currChar!=")"){
            return true;}
        else return false;
    }
    //recursive function for building tree
    Node* insert(queue<string> &input){
//        queue<string> Q = input;
//        while(!Q.empty()){
//            cout<<" "<<Q.front();
//            Q.pop();
//        }
        //get first element
        string element = input.front();
        //cout<<element;
        //pop first element out of queue
        input.pop();
        //create a new node
        Node* v = new Node;
        //if is operand, assign new node to it, serve as base condition
        if (!isOperator(element)) {
            v->value = element;
            //cout<<element;
            return v;
        }
        //if is operator, call itself, and feed the remainder expression
        Node* left = insert(input);
        Node* right = insert(input);
        //assign child node to the current node
        v->left = left;
        v->right = right;
        v->value = element;
        return v;
    }
    void count(){
        cout<<countNodes(root)<<endl;
        cout<<countLeaves(root)<<endl;
         cout<<height(root)<<endl;
    }
    int countNodes(Node* root)
    {
        int count = 1;
        if (root == nullptr) {
            return 0;
        }
        else if (root->left == nullptr && root->right == nullptr)
            return 1;
        else {
            return count + countNodes(root->left) + countNodes(root->right);
        }
    }
    int countLeaves(Node* root)
    {
        if (root == nullptr) {
            return 0;
        }
        else if (root->left == nullptr && root->right == nullptr)
            return 1;
        else {
            return countLeaves(root->left) + countLeaves(root->right);
        }
    }
    int height(Node* curr)
    {
        int count = 1;
        if (curr == nullptr) {
            return 0;
        }
        else if (curr->left == nullptr && curr->right == nullptr)
            return 0;
        else {
            return count + max(height(curr->left),height(curr->right));
        }
    }
    
    //recursive function to traverse a tree, visit leafs first then root
    void printPostfix(Node* root)
    {
        if (root == NULL) {
            return;
        }
        else {
            printPostfix(root->left);
            printPostfix(root->right);
            cout<<root->value;
        }
    }
//recursive function to traverse a tree, visit leafs first then root
//append chars to posftfix string
    void getInfix(Node* root){
        if (root == NULL) {
            return;
        }
        else {
            getInfix(root->left);
            getInfix(root->right);
            postfix.append(root->value);
        }
    }
//using method from assignment2, convert postfix to infix and print
    string printInfix(){
        //cout<<postfix;
        for (int i = 0; i< postfix.size(); i++){
            if (isOperand(postfix.substr(i,1))) {
                p.push(postfix.substr(i,1));
            }
            else{
                string operand1 = p.top();
                //cout<<p.top();
                p.pop();
                string operand2 = p.top();
                //cout<<p2.top();
                p.pop();
                p.push("(" + operand2 + postfix.substr(i,1) + operand1 + ")");
            }
        }
        return p.top();
    }
    //recursive function to traverse a tree, visit node first then leafs
    void printPrefix(Node* root){
        if (root == NULL) {
            return;
        }
        else {
            cout<<root->value;
            printPrefix(root->left);
            printPrefix(root->right);
        }
    }
    
public:
    queue<string> prefix_input;
    stack<string> p;
    string postfix;
   // int numNodes;
    //int numLeaves;
    //int numNodes;
};
