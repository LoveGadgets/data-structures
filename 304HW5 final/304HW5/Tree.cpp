//cs 304 HW5
//Daniel Yi Hong
//student ID: 002244776
//

#include <stdio.h>
#include <string>
#include <queue>
#include <stack>
#include "List.hpp"
#include <iostream>

using namespace std;

class Tree{
    //inner node class to build nodes
    class Node{
    private:
        Node(){
            left = nullptr;
            right = nullptr;
        }
    private:
        int value;
        Node *left;
        Node *right;
        friend class Tree;
    };

public:
    Tree(){
        size = 0;
    }
    //root node of the tree that was built
    Node* root = nullptr;
//    insert method 1, check to see if current node has child at each iteration. if no child, then add the new node to it directly.
    void insert(int value){
        //size is depends on how many time insert funtion is called
        size++;
        //cout<<size<<endl;
        //create a new node
        Node* v = new Node;
        //initialize its value
        v->value = value;
        //if there is no root node, set it to be root node
        if (root == nullptr){
            root = v;
            // cout<<root->value;
            return;
        }
        //otherwise set current variable to point to root node
        Node* current = root;
        //unless break, loop will continue.
        while (1){
            //cout<<current->value<<" ";
            //if inserted value is smaller than current Node value
            if (current->value > value){
                //if current node has no left children, set inserted value to be current node's left children, and break the loop
                if (current->left == nullptr){
                    current->left = v;
                    break;
                }
                //cout<<current->value<<" ";
                //otherwise point the current variable to current node's left children, and continue go down the tree
                current = current->left;
            }
            //if inserted value is larger than current Node value
            else{
                //if current node has no right children, set inserted value to be current node's right children, and break the loop
                if (current->right == nullptr){
                    current->right = v;
                    break;
                }
                 //otherwise point the current variable to current node's right children, and continue go down the tree
                current = current->right;
            }
        }
    }
//    //insert method 2, go down the tree, if exit the while loop that means reach the null node, create a new node under null node's parent node based on value comparison.
//    void insert(int value){
//        size++;
//        //cout<<size<<endl;
//        //create a new node
//        Node* v = new Node;
//        //initialize its value
//        v->value = value;
//        Node* currParent = root;
//        if (root == nullptr){
//            root = v;
//            return;
//        }
//        Node* curr = root;
//
//        while (curr!=nullptr){
//            currParent = curr;
//            // be careful to sign the equal and larger to right consintently.
//            if (value<curr->value)
//                curr = curr->left;
//            else
//                curr = curr->right;
//        }
//
//        if (currParent->value >value ){
//            currParent->left = v;
//        }
//        else {
//            currParent->right = v;
//        }
//    }
    
    int deleteHighest(){
        //each delettion, size decrease by 1
        size--;
        //since its recursive funtion, root node wont be changed until itself is the largest node, after that, root node will be updated to its left child.
        root = deleteLargest(root);
        return maxValue;
    }
    
    //pass root node into the recursive function, it will keep calling until find the largest node, it will either have left child or not, but no right child since its largest. We want to delete it. if it has left child, then now its parent will point to the left child. if it has no left child, then parent will point to null pointer.
    Node* deleteLargest(Node *current){
        //base condition
        if (current->right == nullptr){
            //if base condition reached, largest value is found. sign it the a variable.
            maxValue = current ->value;
            //return largest node's left. either its a node or a null pointer
            return current -> left;
        }
        //starts from root node, go down to largest node.
        current->right = deleteLargest(current->right);
        //when base conditon returned, it will level up return each call until root node's right been signed, then return root node.
        return current;
    }
    void inorder(List &list){
        //alist = new List(size);
        printInfix(root,list);
    }
    //traverse in infix order.
    void printInfix(Node* root, List &list){
        if (root == NULL) {
            return;
        }
        else {
            printInfix(root->left, list);
            //cout<<root->value<<" ";
            list.insert(root->value);
            printInfix(root->right, list);
        }
    }
    bool isEmpty(){
        return size == 0;
    }
    
    //testing function to print the inorder value. not used in this program
    void doInfix(Node* root){
        if (root == NULL) {
            return;
        }
        else {
            doInfix(root->left);
            cout<<root->value<<" ";
            doInfix(root->right);
        }
    }
    //testing function to find the largest value. not used in this program
    Node* findLargest(Node *current){
        if (current->right == nullptr){
            return current;
        }
        current = findLargest(current->right);
        return current;
    }
        
private:
    int size;
    int maxValue;
};

