//
// Created by greg on 19-2-27.
//
#include <iostream>
#include <vector>
using namespace std;

/**
 *92. 背包问题
 * 在n个物品中挑选若干物品装入背包，最多能装多满？假设背包的大小为m，每个物品的大小为A[i]
 * 样例 1:
	输入:  [3,4,8,5], backpack size=10
	输出:  9
 * 样例 2:
	输入:  [2,3,5,7], backpack size=12
	输出:  12
 * */
int backPack(int m, vector<int> &A) {
    // write your code here
    vector<vector<int>> dp(A.size()+1, vector<int>(m+1, 0));
    for (int i=1; i<=A.size(); i++){
        for (int j=m; j>0; j--){
            // 背包容量大于当前物品重量
            // dp[i-1][j] 未装入当前物品，且背包容量为j时背包中的重量
            // dp[i-1][j-A[i-1]] 背包中物品重量为j-A[i-1]时背包中物品的重量
            if (j >= A[i-1])
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-A[i-1]] + A[i-1]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }


    for (size_t i=0; i<dp.size(); i++){
        for (size_t j=0; j<dp[0].size(); j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[A.size()][m];

}

/**
 *
 * 用一维数组来保存背包中物品的重量，
 * dp[j]未存入当前物品时背包中的重量
 * dp[j-A[i]] 表示背包中物品重量为j-A[i]时，
 * */
int backPack1(int m, vector<int> &A) {
    vector<int> dp(m+1, 0);

    for (size_t i=0; i<A.size(); i++){
        for (size_t j=m; j>0; j--){
            if (j >= A[i])
                dp[j] = max(dp[j], dp[j-A[i]] + A[i]);
        }
    }

    return dp[m];
}

int main(){

    int arr[] = {2, 3, 5, 7};
    vector<int> A(arr, arr+ sizeof(arr)/ sizeof(arr[0]));
    int m = 12;
    cout<<backPack1(m, A)<<endl;

    return 0;
}
