//
// Created by greg on 19-4-2.
//
#include <iostream>
#include <vector>
using namespace std;

/**
 * 划分和相等的子集
 * 给定一个数组，判断能否将数组划分成两段，保证两段的和相等
 * 首先求和sum，如果和为奇数，则不能划分成两段
 * 如果和为偶数，则继续处理，判断当前数组中的数字能否组成sum/2
 * 就转换为了背包问题，给定一个数组，给定固定容量的背包，看这组数是否能装满背包
 *
 * */
bool canPartition(vector<int> &nums){
    int sum = 0;
    for (auto num : nums)
        sum += num;
    if (sum & 1)
        return false;

    vector<vector<bool>> dp(nums.size()+1, vector<bool>(sum/2+1, false));
    for (int i=0; i<dp.size(); i++)
        dp[i][0] = true;

    for (int i=1; i<=nums.size(); i++){
        for (int j=1; j<=sum/2; j++){
            if (j >= nums[i-1])
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[nums.size()][sum/2];
}

bool canPartition1(vector<int> &nums) {
    int sum = 0;
    for (auto num : nums)
        sum += num;
    if (sum & 1)
        return false;

    sum /= 2;
    vector<int> dp(sum+1, 0);

    for (int i=0; i<nums.size(); i++){
        for (int j=sum; j>=0; j--){
            if (j >= nums[i])
                dp[j] = max(dp[j-nums[i]] + nums[i], dp[j]);
        }
    }
    return dp[sum]==sum;
}


int main(){
    int arr[] = {1, 5, 11, 5};
    vector<int> nums(arr, arr+ sizeof(arr)/ sizeof(arr[0]));
    cout<<canPartition1(nums)<<endl;
    return 0;
}
