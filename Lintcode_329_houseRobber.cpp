//
// Created by greg on 19-3-13.
//
#include <iostream>
#include <vector>
using namespace std;

/**
 * 房屋偷盗，不能偷相邻的房间
 * */
long long houseRobber(vector<int> &A) {
    // write your code here
    if (A.size() < 1)
        return 0;
    vector<int> dp(A.size(), 0);

    dp[0] = A[0];
    long long res = A[0];
    for (int i=1; i<A.size(); i++){
        dp[i] = A[i];
        for (int j=i-2; j>=0; j--)
            dp[i] = max(A[i]+dp[j], dp[i]);

        res = res > dp[i] ? res : dp[i];
    }
    return res;
}

long long houseRobber1(vector<int> &A) {
    if (A.size() < 1)
        return 0;

    long long pre = A[0];
    long long cur = max(A[0], A[1]);
    for (int i=2; i<A.size(); i++){
        long long tmp = max(pre + A[i], cur);
        pre = cur;
        cur = tmp;
    }

    return cur;
}


int main(){
    int arr[] = {3, 4, 7};
    vector<int> A(arr, arr + sizeof(arr)/ sizeof(arr[0]));
    cout<<houseRobber1(A)<<endl;

    return 0;
}
