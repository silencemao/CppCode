//
// Created by greg on 19-2-22.
//
#include <iostream>
#include <vector>
using namespace std;

/**
 * 斐波那切数列
 * */
int climbStairs(int n) {
    // write your code here
    int arr[] = {0, 1, 2};
    if (n < 3)
        return arr[n];

    for (size_t i=3; i<=n; i++){
        int tmp = arr[1] + arr[2];
        arr[1] = arr[2];
        arr[2] = tmp;
    }

    return arr[2];
}

int climbStairs1(int n){
    if (n==0)
        return 0;
    if (n==1)
        return 1;
    if (n==2)
        return 2;

    return climbStairs(n-1) + climbStairs(n-2);

}

int main(){
    for (size_t i=0; i<10; i++){
        cout<<climbStairs(i)<<" "<<climbStairs1(i)<<endl;
    }

    return 0;
}
