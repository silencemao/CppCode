//
// Created by greg on 19-3-29.
//

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &res, vector<int> &cur, vector<int> nums, int target, int index){
//    if (target < 0)
//        return;
    if (target==0){
        res.push_back(cur);
        return;
    }

    for (int i=index; i<nums.size(); i++){
        if (target >= nums[i]){
            cur.push_back(nums[i]);
            dfs(res, cur, nums, target-nums[i], index);  // 此处用i和用index的区别
            cur.pop_back();
        }
    }
}

int backPackVI(vector<int> &nums, int target) {
    // write your code here
    vector<vector<int>> res;
    vector<int> cur;
    dfs(res, cur, nums, target, 0);
    return res.size();
}

/**
 * 给出一个都是正整数的数组 nums，其中没有重复的数。从中找出所有的和为 target 的组合个数。
 *
 * 输入: nums = [1, 2, 4] 和 target = 4
 * 输出: 6
 * [1, 1, 1, 1]
 * [1, 1, 2]
 * [1, 2, 1]
 * [2, 1, 1]
 * [2, 2]
 * [4]
 * 
 *
 * */
int backPackVI2(vector<int> &nums, int target){
    vector<int> dp(target+1, 0);
    dp[0] = 1;
    for (int i=1; i<=target; i++){
        for (auto num : nums){
            if (i >= num)
                dp[i] += dp[i-num];
        }
    }
    return dp.back();
}


int main(){
    int arr[] = {1, 2, 4};
    vector<int> nums(arr, arr+ sizeof(arr)/ sizeof(arr[0]));
    int target = 32;
    cout<<backPackVI2(nums, target)<<endl;

    return 0;
}