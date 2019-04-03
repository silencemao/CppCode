//
// Created by greg on 19-4-3.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * https://blog.csdn.net/weixin_37373020/article/details/81018538
 * 最大整除子集
 * */
vector<int> largestDivisibleSubset(vector<int> &nums) {
    // write your code here
    if (nums.size() < 1)
        return {};
    sort(nums.begin(), nums.end());
    vector<int> dp(nums.size(), 0);
    vector<int> index(nums.size(), -1);  // 记录满足子集的数字索引
    int max_len = 0, max_index = -1;

//    dp[0] = 1;
    for (int i=0; i<nums.size(); i++){
        dp[i]  = 1;
        for (int j=0; j<i; j++){
            if (nums[i] % nums[j]==0){
                if (dp[i] < dp[j] + 1) {  // 这里是为什么呢 为什么不是dp[i] = max(dp[i], dp[j]) + 1;
                    dp[i] = dp[j] + 1;
                    index[i] = j;
                }
            }
            if (dp[i] > max_len){
                max_len = dp[i];
                max_index = i;
            }
        }
    }
//
    for (auto num : nums)
        cout<<num<<" ";
    cout<<endl;
    for (auto num : dp)
        cout<<num<<" ";
    cout<<endl;
    for (auto num : index)
        cout<<num<<" ";
    cout<<endl;

    cout<<max_len<<" "<<max_index<<endl;
    vector<int> res;
    while (1){
        if (max_index != -1){
            res.push_back(nums[max_index]);
            max_index = index[max_index];
        }
        else
            break;
    }

    return res;
}

int main(){

    int arr[] = {2,3,5,7,11,13,17,19,23,31,1000000007};
    vector<int> nums(arr, arr+ sizeof(arr)/ sizeof(arr[0]));
    vector<int> res = largestDivisibleSubset(nums);
    for (auto num : res)
        cout<<num<<" ";
    cout<<endl;

    return 0;
}