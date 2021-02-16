#include <iostream>
#include <vector>

using namespace std;

class stack{
public:
    stack(): index(-1),arr {}
    void push(int elem){
        if (index+1 == MAXSZ)
            cout << "stack is full"<<endl;

        } else {
            arr[++index]=elem;
        }
    int pop(){
        if (index == -1)
            cout<<"cannot pop empty stack"<<endl;
        else return arr[index--];
        return null;
    }
    int peek()const{
        if (index !=0){
            return arr[index];
            else return null;
        }
private:
    int arr[MAXSZ];
    int index;
    }
}


stack s;
s.push(10);
s.


void merge(vector<int>& arr int p, int q, int r){
    int n1= q-p+1;
    int n2 = r-q;
    vector<int> L(n1+1);
    vector<int> R(n2+1);
    for (int i =0; i< n1; i++)
        long
}

void mergesort(vector<int>& arr, int p, int r){
    if (q<r){
        int q = (q+r)/2; //divide step
        mergesort(arr,p,q);
        mergesort(arr,q+1;r);
        merge(arr,p,q,r);
        
    }
    
}

int main()
{
    vector<int> arr = {3,2,1,7,4,2,1,9};
    mergesort(arr,0, arr,size() -1);
    
}
