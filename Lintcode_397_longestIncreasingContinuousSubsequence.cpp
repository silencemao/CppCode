//
// Created by greg on 19-3-15.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 * 给定一个整数数组（下标从 0 到 n-1， n 表示整个数组的规模），请找出该数组中的最长上升连续子序列。
 * （最长上升连续子序列可以定义为从右到左或从左到右的序列。）
 *
 * */
int longestIncreasingContinuousSubsequence(vector<int> &A) {
    // write your code here
    if (A.size() < 1)
        return 0;
    int left = 1, right = 1;  // 分别标记上升和下降子序列的长度
    int res = 1;
    for (int i=1; i<A.size(); i++){
        if (A[i] > A[i-1]){   // 如果是上升
            left++;
            right = 1;
        }
        else if (A[i] < A[i-1]){  // 如果是下降
            left = 1;
            right++;
        }
        else {                   // 如果是相等
            left = 1;
            right = 1;
        }
        res = max(max(left, right), res);
    }
    return res;
}

int main(){
    int arr[] = {5, 1, 2, 3, 4, 6, 5, 4, 3, 2};
    vector<int> A(arr, arr + sizeof(arr)/ sizeof(arr[0]));
    cout<<longestIncreasingContinuousSubsequence(A)<<endl;

    return 0;
}