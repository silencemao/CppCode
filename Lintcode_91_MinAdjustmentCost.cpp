//
// Created by greg on 19-2-21.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 * 给一个整数数组，调整每个数的大小，使得相邻的两个数的差不大于一个给定的整数target，
 * 调整每个数的代价为调整前后的差的绝对值，求调整代价之和最小是多少。
 * 样例 1:
	输入:  [1,4,2,3], target=1
    输出:  2
   样例 2:
	输入:  [3,5,4,7], target=2
	输出:  1

你可以假设数组中每个整数都是正整数，且小于等于100。
 *
 * */

int minAdjustmentCost(vector<int> &A, int target){
    vector<vector<int>> dp(A.size()+1, vector<int>(101, INT32_MAX));
    for (size_t i=0; i<101; i++)
        dp[0][i] = 0;

    for (int i=1; i<=A.size(); i++){
        for (int j=0; j<101; j++){
            int left = (j-target) > 1 ? (j-target) : 1;
            int right = (j+target) < 100 ? (j+target) : 100;

            for (int k=left; k<=right; k++){
                dp[i][j] = min(dp[i][j], dp[i-1][k] + abs(j-A[i-1]));
            }
        }
    }

    int res = INT32_MAX;
    for (size_t i=0; i<101; i++)
        if (res > dp[A.size()][i])
            res = dp[A.size()][i];

    return res;

}

int main(){

    int arr[] = {3, 5, 4, 7};
    int target = 2;
    vector<int> A(arr, arr + sizeof(arr)/ sizeof(arr[0]));
    cout<<minAdjustmentCost(A, target)<<endl;

    return 0;
}