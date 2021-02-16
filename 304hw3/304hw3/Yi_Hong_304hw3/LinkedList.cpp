//cs 304 HW3
//Daniel Yi Hong
//student ID: 002244776


//#include "LinkedList.hpp"
#include <iostream>
#include <vector>

using namespace std;
class LinkedList{

  class Node {
  private:
      Node(){
          next = nullptr;
      }
  private:
      Node *next;
      int elem;
      friend class LinkedList; // declare linkedlist as a friend, so it can access Node's fields
  };
 
    
public:
       LinkedList(){
             head = nullptr;
             tail = nullptr;
             }
         // destructor - call remove front (which deletes nodes) until the list is empty
        // ~LinkedList() {
            // while (!empty())
               //  removeFront();
        // }

    // get first element in the list
    int  front()const { return head->elem; }

    // get last element in the list
    int  back() const { return tail->elem; }

    // check if the list is empty, if it is, return true
    bool  empty()const { return head == nullptr; }

    // add a new element to the front of the list
    void   insertFirst(const int newElem) {
        Node* v = new Node; // initialize new node to hold element
        v->elem = newElem; // set the new node's value
        if (head != nullptr) { // if the list is not empty
            //head->prev = v; // set the current head's previous to point to our new node
            v->next = head; // set the new node's next to point to current head
        }
        else tail = v; // if the list was empty when addFront(..) is called, set the tail as our new node
        head = v;  // finally, set the head as the new node
    }

    // add an element to back of list - similar to addFront
    void  addBack(const int newElem) {
        Node* v = new Node;
        v->elem = newElem;
        if (tail != nullptr) {
            tail->next = v;
            //v->prev = tail;
        }
        else head = v;
        tail = v;
    }

    //add a node AFTER the node current, holding the value 'newElem'
    void  addAfter(Node* current, int newElem) {
        Node* v = new Node;  // initialize new node
        v->elem = newElem;  // set new node's value to be newElem
        v->next = current->next; // set new node's 'next' to be current node's next
        current->next = v;
        //v->prev = current; // set current node's 'previous' to be current node
        // note - the effect of the above two operations is to place the new node between
        // current and and current->next
        if (v->next == nullptr) // make sure v's next is not null
            //v->next->prev = v; // set v-> next's previous pointer to point to v
        //else
            tail = v; // if v-> next is null, then we assume v is the only node so we set tail=v
    }

    //remove the element at the front of the list, and update head to point to the next node in the list
    void  removeFront() {
        Node* old = head;
        head = old->next;

        //if (head != nullptr)
           // head->prev = nullptr;
//        delete old;
    }

    // random function to get the minimum value of linked list - not part of typical linked list definition
    int  getMin() {
        Node* current = head;
        int min = 999999999;
        while (current != nullptr) {
            if (current->elem < min)
                min = current->elem;
            current = current->next;
        }
        return min;
    }

    // return the length of a linked list
    int length(Node *inputhead){
        Node* current = inputhead;
        int count = 0;
        for(; current != nullptr; current =current ->next){
            count ++;
        }
        return count;
    }
 //find middle head of a linked list and break the list into 2 parts
    Node* middlehead (Node *inputhead){
        int len = length(inputhead);
        //cout<<len;
        Node* middleHead = inputhead;
        Node* temp;
        if (len/2 == 1){
            middleHead = inputhead -> next;
            inputhead -> next = nullptr;
        }
        else{
            for (int i = 0; i<(len/2-1); i++){
                middleHead = middleHead -> next;
            }
            temp = middleHead -> next;
            middleHead -> next = nullptr;
            middleHead = temp;
        }
        return middleHead;
    }
  
//merge two list with elements putting in correct order
    Node* merge(Node* &frontHead, Node* &middleHead){
        Node* mergeListHead;
        //base case
        if (frontHead == nullptr)
            return middleHead;
        else if (middleHead == nullptr)
            return frontHead;
        if (frontHead->elem < middleHead->elem){
            mergeListHead = frontHead;
            mergeListHead -> next = merge(frontHead->next, middleHead);
        }
        else{
            mergeListHead = middleHead;
            mergeListHead->next = merge(frontHead,middleHead->next);
        }
        return mergeListHead;
}
//break linked list into indivisual element and merge
    void callmergesort(Node *&inputhead){
        if (inputhead->next == nullptr) return;
        Node* frontHead = inputhead;
        Node* middleHead = middlehead(inputhead);
        callmergesort(frontHead);
        callmergesort(middleHead);
        inputhead = merge(frontHead, middleHead);
}
    //call recursion function with head of the linked list
    void mergesort(){
        callmergesort(head);
    }

    // simple display function, prints out values at all nodes
    void  display() const {
        Node* current = head;
        //int counter = 0;
        while (current != nullptr) {
            //cout << "node position: " << counter++ << ", elem value: " << //current->elem << endl;
            cout<< current ->elem<<" ";
            current = current->next;
        }
        cout<<endl;
    }
    private:
        Node* head;
        Node* tail;
    };
    // fields of the linked list
