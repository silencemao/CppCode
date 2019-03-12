//
// Created by greg on 19-3-12.
//
#include <iostream>
#include <vector>
using namespace std;

int climbStairs2(int n){
    int arr[] = {1, 1, 2, 4};

    if (n < 4)
        return arr[n];
    int fibOne = 1, fibTwo = 2, fibThree = 4;
    for (int i=4; i<=n; i++){
        int tmp = fibOne + fibTwo + fibThree;
        fibOne = fibTwo;
        fibTwo = fibThree;
        fibThree = tmp;
    }
    return fibThree;
}

int main(){
    cout<<climbStairs2(5)<<endl;

    return 0;
}
