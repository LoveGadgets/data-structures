//cs 304 HW3
//Daniel Yi Hong
//student ID: 002244776

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>

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
         ~LinkedList() {
             while (!empty())
                 removeFront();
         }
    int front() const;
    int back() const;
    void insertMiddle(const int newElem);
    void insertFirst(const int newElem);
    void removeFront();
    //void removeBack(); doesnt apply to singly linkedlist
    bool empty()const;
    void addBack(const int newElem);
    void addAfter(Node* current, int newElem);
    //void addBefore(Node* current, int newElem);doesnt apply to singly linkedlist
    void display() const;
    int length(Node *head);
    int getMin();
    Node* middlehead(Node *head);
    void mergesort();


private:
    Node* head;
    Node* tail;
};

#endif /* LinkedList_hpp */
