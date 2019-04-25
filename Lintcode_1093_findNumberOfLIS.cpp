//
// Created by greg on 19-4-25.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 * 最长上升子序列个数
 * 输入：[1,3,5,4,7]
 * 输出：2
 * [1,3,5,7]  [1,3,4,7]
 * */
int findNumberOfLIS(vector<int> &nums) {
    // Write your code here
    if (nums.size()<1)
        return 0;
    size_t length = nums.size();
    vector<int> dp(length, 1);
    int maxLen = 1;
    for (int i=1; i<length; i++){
        for (int j=0; j<i; j++){
            if (nums[j] < nums[i])
                dp[i] = max(dp[j] + 1, dp[i]);  // 这里要注意
        }
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}


int findNumberOfLIS1(vector<int> &nums) {
    if (nums.size() < 1)
        return 0;
    size_t length = nums.size();
    vector<int> dp(length, 1);
    vector<int> ans(length, 1);  // 记录最长上升子序列的个数
    int max_len = 1;
    for (int i=1; i<length; i++){
        for (int j=0; j<i; j++){
            if (nums[j] < nums[i] && (dp[j] + 1) > dp[i]){ //满足上升子序列 单dp[j]+1>dp[i] 相当于生成一个新的最长上升子序列了
                dp[i] = dp[j] + 1;
                ans[i] = ans[j];    // ans[i]=ans[j]　表示最长上升子序列的个数和以j结尾的个数一样
            }
            else if (nums[j] < nums[i] && dp[j]+1==dp[i]) // dp[j]+1=dp[i]表示以i结尾的最大长度maxLen没变，但是maxLen多了一个
                ans[i] += ans[j];
        }
        max_len = max_len > dp[i] ? max_len : dp[i];
    }

    int cont = 0;
    for (int i=0; i<length; i++){
        if (dp[i]==max_len)
            cont += ans[i];
    }
    return cont;
}
int main(){
    int arr[] = {1, 3, 5, 4, 7};
    vector<int> nums(arr, arr+ sizeof(arr)/ sizeof(arr[0]));
    cout<<findNumberOfLIS1(nums)<<endl;

    return 0;
}