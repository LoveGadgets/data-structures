//
//  LinkedList.cpp
//  304hw3
//
//  Created by Daniel on 2/25/20.
//  Copyright © 2020 Daniel. All rights reserved.
//

#include "LinkedList.hpp"
#include <iostream>
#include <vector>

using namespace std;


/*
Node class. holds a pointer to the next and previous nodes in the linked list
*/
/*
LinkedList class.
 string output = "";
  for (int i = 0; i< postfixString.size(); i++){
      output+=postfixString[i];}
      
  return output;
*/
 
    // get first element in the list
    int LinkedList:: front()const { return head->elem; }

    // get last element in the list
    int LinkedList:: back() const { return tail->elem; }

    // check if the list is empty, if it is, return true
    bool LinkedList:: empty()const { return head == nullptr; }

    // add a new element to the front of the list
    void  LinkedList:: addFront(const int newElem) {
        Node* v = new Node; // initialize new node to hold element
        v->elem = newElem; // set the new node's value
        if (head != nullptr) { // if the list is not empty
            head->prev = v; // set the current head's previous to point to our new node
            v->next = head; // set the new node's next to point to current head
        }
        else tail = v; // if the list was empty when addFront(..) is called, set the tail as our new node
        head = v;  // finally, set the head as the new node
    }

    // add an element to back of list - similar to addFront
    void LinkedList:: addBack(const int newElem) {
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
    void LinkedList:: addAfter(Node* current, int newElem) {
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
    void LinkedList:: addBefore(Node* current, int newElem){
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
    void LinkedList:: removeFront() {
        Node* old = head;
        head = old->next;

        if (head != nullptr)
            head->prev = nullptr;
        delete old;
    }

    // remove element at back of list, update tail to point to previous node in list
    void LinkedList:: removeBack() {
        Node* old = tail;
        tail = old->prev;
        if (tail != nullptr)
            tail->next = nullptr;
        delete old;
    }

    // random function to get the minimum value of linked list - not part of typical linked list definition
    int LinkedList:: getMin() {
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
    void LinkedList:: display() const {
        Node* current = head;
        int counter = 0;
        while (current != nullptr) {
            cout << "node position: " << counter++ << ", elem value: " << current->elem << endl;
            current = current->next;
        }
    }

    // fields of the linked list
