//
// Created by greg on 19-2-28.
//
#include <iostream>
#include <vector>
using namespace std;

/**
 * 贪心
 * */
bool canJump(vector<int> &A) {
    // write your code here
    int maxL = 0;  // 记录当前位置可以走到的最远位置
    for (int i=0; i<A.size(); i++){
        if (i > maxL)   // 如果当前位置的索引大于上一步能到达的最大值，说明从前任意位置跳都跳不过来
            return false;
        maxL = (A[i] + i) > maxL ? (A[i] + i) : maxL;  // 更新最大值
    }
    return true;
}

/**
 * 动态规划
 *
 * */

bool canJump1(vector<int> &A){
    vector<bool> dp(A.size(), false);
    dp[0] = true;  // 第一个位置肯定可以到达

    for (int i=1; i<A.size(); i++){  // 遍历是否可以到达i位置
        for (int j=0; j<i; j++){

            if (dp[i])              // 如果到达过，就跳过，
                break;
            dp[i] = (dp[j] && (j + A[j] >= i));  //更新dp[i]
        }
    }
    return dp[A.size()-1];
}

int main(){
    int arr[] = {2, 3, 1, 1, 4};
    vector<int> A(arr, arr + sizeof(arr)/ sizeof(arr[0]));
    cout<<canJump1(A)<<endl;
    return 0;
}
