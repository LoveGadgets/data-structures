//
//  double linkedlist.cpp
//  304midterpractice
//
//  Created by Daniel on 2/17/20.
//  Copyright © 2020 Daniel. All rights reserved.
//

#include "double linkedlist.hpp"
#include <iostream>
#include <vector>

using namespace std;


/*
Node class. holds a pointer to the next and previous nodes in the linked list
*/
class Node {
private:
    Node(){
        next = nullptr;
        prev = nullptr;
    }
private:
    Node *next;
    Node *prev;
    int elem;
    friend class LinkedList; // declare linkedlist as a friend, so it can access Node's fields
};

class LinkedList {
public:

    // constructor, just initialize head and tail as nullptrs
    LinkedList(){
        head = nullptr;
        tail = nullptr;
        }
    // destructor - call remove front (which deletes nodes) until the list is empty
    ~LinkedList() {
        while (!empty())
            removeFront();
    }

    // get first element in the list
    int front()const { return head->elem; }

    // get last element in the list
    int back() const { return tail->elem; }

    // check if the list is empty, if it is, return true
    bool empty()const { return head == nullptr; }


    
    // add an element to back of list - similar to addFront
    void addBack(const int newElem) {
        Node* v = new Node;
        v->elem = newElem;
        if (tail != nullptr) {
            tail->next = v;
            v->prev = tail;
        }
        else head = v;
        tail = v;
    }

    //add a node AFTER the node current, holding the value 'newElem'
    void addAfter(Node* current, int newElem) {
        Node* v = new Node;  // initialize new node
        v->elem = newElem;  // set new node's value to be newElem
        v->next = current->next; // set new node's 'next' to be current node's next
        v->prev = current; // set current node's 'previous' to be current node
        // note - the effect of the above two operations is to place the new node between
        // current and and current->next
        if (v->next != nullptr) // make sure v's next is not null
            v->next->prev = v; // set v-> next's previous pointer to point to v
        else
            tail = v; // if v-> next is null, then we assume v is the only node so we set tail=v
    }

    // add an element before 'current', similar to addNext(..)
    void addBefore(Node* current, int newElem){
        Node* v = new Node;
        v->elem = newElem;
        v->prev = current->prev;
        v->next = current;
        if (v->prev != nullptr)
            v->prev->next = v;
        else
            head = v;
    }

    //remove the element at the front of the list, and update head to point to the next node in the list
    void removeFront() {
        Node* old = head;
        head = old->next;

        if (head != nullptr)
            head->prev = nullptr;
        delete old;
    }

    // remove element at back of list, update tail to point to previous node in list
    void removeBack() {
        Node* old = tail;
        tail = old->prev;
        if (tail != nullptr)
            tail->next = nullptr;
        delete old;
    }

    // random function to get the minimum value of linked list - not part of typical linked list definition
    int getMin() {
        Node* current = head;
        int min = 999999999;
        while (current != nullptr) {
            if (current->elem < min)
                min = current->elem;
            current = current->next;
        }
        return min;
    }

    // simple display function, prints out values at all nodes
    void display() const {
        Node* current = head;
        int counter = 0;
        while (current != nullptr) {
            cout << "node position: " << counter++ << ", elem value: " << current->elem << endl;
            current = current->next;
        }
    }
    
    // add a new element to the front of the list
    void addFront(const int newElem) {
        Node* v = new Node; // initialize new node to hold element
        v->elem = newElem; // set the new node's value
        if (head != nullptr) { // if the list is not empty
            head->prev = v; // set the current head's previous to point to our new node
            v->next = head; // set the new node's next to point to current head
        }
        else tail = v; // if the list was empty when addFront(..) is called, set the tail as our new node
        head = v;  // finally, set the head as the new node
    }
    
    void compressZero(){
        Node* current = head;
        while (current-> next != nullptr){
            if (current -> elem == 0){
                current->prev ->next = current -> next;
                current->next ->prev = current -> prev;
            }
        }
    }
    
    void recursiveRemoveDup(Node* current){
        if (current ->next ->elem == current -> elem){
            current->prev ->next = current -> next;
            current->next ->prev = current -> prev;
        }
        else current = current -> next;
        
        
        if (current != nullptr)
        recursiveRemoveDup(current);
    }
    
    void insearByIndex(int element, int index){
        Node * current = head;
        while (index >= 0){
            if (current -> next != nullptr){
                current = current -> next;
            }
            index --;
        }
           `
    }
    
    
    
    bool areEqual (Node *head1, Node *head2){
        if (head1 == nullptr && head2 == nullptr)
            return true;
        
        
    }

    // fields of the linked list
private:
    Node* head;
    Node* tail;
};


    
