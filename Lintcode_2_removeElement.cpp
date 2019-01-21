//
// Created by greg on 17-9-24.
//
#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int> &A, int elem){
    int index = 0;
    for (int i=0; i<A.size(); i++){
        if (A[i] != elem){
            A[index] = A[i];
            index ++;
        }
    }
    return index;
}

int main(){
//    vector<int> A(10, 4);
//    A.insert(A.begin(), 3, 10);
//    for (int i=0; i<A.size(); i++){
//        cout<<A[i]<<endl;
//    }
//    cout<<removeElement(A, 4);

    string *str;

    return 0;
}
