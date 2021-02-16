//
//  Exam.cpp
//  304hw3
//
//  Created by Daniel on 2020-04-09.
//  Copyright © 2020 Daniel. All rights reserved.
//


#include <iostream>
#include <stack>

using namespace std;
class Exam{
public:
    Exam(){

    }
    
//    stack<int> sort(stack<int> &S)
//    {
//  //      cout<<S.top();
// //       S.pop();
//
//        while (!S.empty())
//        {
//            int num = S.top();
//            S.pop();
//            while (!sorted.empty() && sorted.top() < num )
//            {
//                //cout<<sorted.top()<<endl;
//                S.push(sorted.top());
//                sorted.pop();
//            }
//            sorted.push(num);
//        }
//        //cout<<sorted.top();
//        return sorted;
//    }
    


       void sort(stack<int> &S)
       {
           //stack<int> temp;
           temp.swap(S);
           while (!temp.empty())
           {
               int num = temp.top();
               temp.pop();
               while (!S.empty() && S.top() < num )
               {
                   temp.push(S.top());
                   S.pop();
               }
               S.push(num);
           }
       }
//    void transfer(stack<int> &stack1, stack<int> &stack2){
//        stack<int> temp;
//        while (!stack1.empty()){
//            temp.push(stack1.top());
//            stack1.pop();
//        }
//        while (!temp.empty()){
//            stack2.push(temp.top());
//            temp.pop();
//        }
//    }
    

    void transfer(stack<int> &stack1, stack<int> &stack2){
        int bottom;
        int num1=0;
        int num2=0;
        while (!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
            num1++;
        }
        while (num1!=0){
            bottom = stack2.top();
            stack2.pop();
            num1--;
            num2 = num1;
            while (num2!=0){
                stack1.push(stack2.top());
                stack2.pop();
                num2--;
        }
            stack2.push(bottom);
            while (!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
    }
    
    
    
    
//    void stackTransfer(struct stack *s1, struct stack *s2)
//    {
//               int x; // considering the two stacks contain integer values
//               if(empty(&s1))
//                     return;
//               x=pop(s1);
//               stackTransfer(&s1,&s2);
//               push(&s2,x);
//    }
    
     int Multiply(int x, int y){
//         if (x < y)
//             return Multiply(y, x);
         if (y != 0)
             return (x + Multiply(x, y - 1));
         else
             return 0;
     }
    int multiply(int x, int y){
        //reduce recursion call improve efficiency
        if (abs(x)<abs(y))
            return multiply(y, x);
        //consider negative numbers
        if ((x<0 && y<0) || (x>0 && y<0)){
            x=-x;
            y=-y;
        }
        //base condition
        if (x==0 || y == 0)
            return 0;
        x= x + multiply(x, y - 1);
        return x;
    }
private:
    //cout<<stack1.top();
    //stack<int> temp2;
    stack<int> temp;
};
