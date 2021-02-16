//cs 304 HW5
//Daniel Yi Hong
//student ID: 002244776
//
#include <iostream>
#include <string>
#include "Tree.cpp"
#include "List.hpp"
#include "Heap.cpp"
#include <cstdio>
#include <ctime>
using namespace std;

int main(int argc, const char * argv[]) {
    int n = 100;
    List operations (n);
    //srand(time(0));
    srand( static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i<n; i++){
        int number = rand() %100;
        //cout<<number<<" ";
        operations.insert(number % 100);
    }
    cout << "random elements: "<<endl;
    operations.display();
    cout<<endl;
    
    Heap H(n);
    Tree T;
    //insert random elements in the heap and tree
    clock_t start1;
    start1 = clock();
    for (int i=0; i<n; i++){
        //cout<<operations.getElement(i);
        H.insert(operations.getElement(i));
    }
    double duration1 = ( clock() - start1 ) / (double) CLOCKS_PER_SEC;
    cout<<"duration of insert heap is : "<<duration1<<endl;
    
    clock_t start2;
    start2 = clock();
    for (int i=0; i<n; i++){
        //cout<<operations.getElement(i);
        T.insert(operations.getElement(i));
    }

    double duration2 = ( clock() - start2 ) / (double) CLOCKS_PER_SEC;
    cout<<"duration of insert tree is : "<<duration2<<endl;

    List list1(n);
    List list2(n);
    //apply deleteHighest on heap and tree
    clock_t start3;
    start3 = clock();
    while (!H.isEmpty()){
       list1.insert(H.deleteHighest());
      // H.display();
       //cout<<endl;
    }
    double duration3 = ( clock() - start3 ) / (double) CLOCKS_PER_SEC;
    cout<<"duration of heap deleteHIGH is : "<<duration3<<endl;
    
    clock_t start4;
    start4 = clock();
    while (!T.isEmpty()){
        list2.insert(T.deleteHighest());
    }
    double duration4 = ( clock() - start4 ) / (double) CLOCKS_PER_SEC;
    cout<<"duration of tree deleteHIGH is : "<<duration4<<endl;
    
    cout<<"Deleted from the Heep:"<<endl;
    list1.display();
    cout<<endl;
    cout<<"Deleted from the tree:"<<endl;
    list2.display();
    cout<<endl;
    if (list1.compare(list2))
        cout<<"Equal lists"<<endl<<endl;
    else cout<<"Not Equal"<<endl<<endl;

    //Restoring the heap and the tree
    Heap H2(n);
    Tree T2;
    for (int i=0; i<n; i++){
        H2.insert(operations.getElement(i));
        T2.insert(operations.getElement(i));
    }
    
    //Sorting heap and tree and store results in two lists
    List heapList(n);
    clock_t start5;
    start5 = clock();
    H2.HeapSort();
    double duration5 = ( clock() - start5 ) / (double) CLOCKS_PER_SEC;
    cout<<"duration of heap sort is : "<<duration5<<endl;
    H2.heapToList(heapList);
    List treeList(n);
    
    clock_t start6;
    start6 = clock();
    T2.inorder(treeList);
    double duration6 = ( clock() - start6 ) / (double) CLOCKS_PER_SEC;
    cout<<"duration of tree sort is : "<<duration6<<endl;
  
    cout<< "Heapsort Display:"<<endl;
    heapList.display();
     cout<<endl;
    cout<< "Inorder Display:"<<endl;
    treeList.display();
    cout<<endl;
    
    if (heapList.compare(treeList))
        cout<<"Equal lists"<<endl<<endl;
    else cout<<"Not Equal"<<endl<<endl;

    
    //    cout<<"postfix: ";
    //    T.printInfix(T.root);
}
