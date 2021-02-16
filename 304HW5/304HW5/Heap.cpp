//
//  Heap.cpp
//  304HW5
//
//  Created by Daniel on 2020-04-01.
//  Copyright © 2020 Daniel. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include "List.hpp"
#include <iostream>
#include <stack>
using namespace std;

class Heap{
public:
    //constructor
    Heap(int n){
        currSize = 0;
        //user define the max size of the array.
        arraySize = n;
        //create a vector of size n and fill with 0s;
//        for (int i = 0; i<vectorSize;i++){
//            nodes.push_back(0);
//        }
        nodes = new int[n];
        //sort = new int[n];
    }
    //insert value into tree, rearrange the tree at each insertion
    void insert(int value){
        //current node's index, since count from 0, size is 1 larger than index
        int index = currSize;
        //currSize is size of numbers being inserted; at each insert, set the value at current index to the value of inserted, and increase currSize by 1
        nodes[currSize] = value;
        currSize++;
        //if current node's index >0 and current node's value is larger than parent node's value, swap them and and set index to parent node's index (since it's swapped), afterwards, repeat action again until reach index = 0 (which is root node)
        while (index > 0 && nodes[index] > nodes[parentIndex(index)]){
            swap(index, parentIndex(index));
            index = parentIndex(index);
        }
    }
    //apple deleteHighest function, and insert each return value(highest value) into a stack
    void HeapSort(){
        for (int i=0; i<arraySize; i++){
            //cout<<deleteHighest()<<" ";
            sort.push(deleteHighest());
        }
    }
    //pop the stack, insert the value to list. since the smallest value is on the top, the list will be in assending order.
    void heapToList(List &list){
        for (int i=0; i< arraySize; i++){
            list.insert(sort.top());
            sort.pop();
        }
    }
    //delete the root node, then rearrange the tree
    int deleteHighest(){
        //value of root node;
        int deletedNum = nodes[0];
        //set root node's value to value of last leave node, then decrease size
        nodes[0] = nodes[currSize - 1];
        currSize--;
        //set current index to 0
        int index = 0;
        //at each removeval, need to reconstruct the tree so that new root node will have the largest value. move current root node down the tree until find the correct spot, which is smaller than parent node but larger than sub nodes.
        //as long as it is not a parent(which is larger than sub nodes) and it doesnt reach beyond the last leave node, keep moving it down the tree
        while (!isParent(index) && index <= currSize){
            int larger = largerSubIndex(index);
            swap(index,larger);
            index = larger;
        }
        return deletedNum;
    }
    //test to see if sub nodes are small then current node
    bool isParent(int index){
        //if doesn't have left sub node, automatically true
        if (leftSubIndex(index) >= currSize){
            return true;
        }
        //if doesnt have right sub node, then true if its larger than left node
        if (rightSubIndex(index) >= currSize)
            return nodes[index] >= nodes[leftSubIndex(index)];
        //otherwise, true if larger than left and right sub node
        return nodes[index] > nodes[leftSubIndex(index)]
        && nodes[index] > nodes[rightSubIndex(index)];
    }
    //return index of sub node that has larger value than current node
    int largerSubIndex(int index){
        //for cases that current node is not valid parent, case 1, has no right sub node, then return left sub node index, case 2, left sub node larger than right sub node, then return left sub node index
        int larger = leftSubIndex(index);
        //the only case to return right sub node index is when righ sub large than left sub
        if (nodes[leftSubIndex(index)]<nodes[rightSubIndex(index)])
                 larger = rightSubIndex(index);
        return larger;
    }
     //calculate parent node's index
    int parentIndex(int index){
        return (index -1) / 2;
    }
    //return left sub node index
    int leftSubIndex(int index){
        return index * 2 +1;
    }
    //return right sub node index
    int rightSubIndex(int index){
        return index * 2 +2;
    }
    //swap values of two nodes
    void swap(int node1, int node2){
        int temp = nodes[node1];
        nodes[node1] = nodes[node2];
        nodes[node2] = temp;
    }
    //if size of numbers is 0, then its empty
    bool isEmpty(){
        return currSize == 0;
    }
    //its a tree structure, when display numbers, it will display parent nodes first, from left to right then sub nodes left to right repeat until bottom leaves.
    void display(){
        for (int i=0; i<currSize; i++){
            cout<<nodes[i]<<" ";
        }
    }
private:
    //vector<int> nodes;
    int *nodes;
    //int *sort;
    int arraySize;
    int currSize;
    stack<int> sort;
};
