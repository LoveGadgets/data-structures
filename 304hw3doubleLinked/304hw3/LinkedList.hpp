//
//  LinkedList.hpp
//  304hw3
//
//  Created by Daniel on 2/25/20.
//  Copyright © 2020 Daniel. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>

class LinkedList{

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
    void addFront(const int newElem);
    void removeFront();
    void removeBack();
    bool empty()const;
    void addBack(const int newElem);
    void addAfter(Node* current, int newElem);
    void addBefore(Node* current, int newElem);
    void display() const;
    int getMin();
private:
    Node* head;
    Node* tail;
};

#endif /* LinkedList_hpp */
