//
// Created by greg on 19-3-7.
//

#include <iostream>
#include <vector>
using namespace std;


/**
 * 乘积最大连续子序列
 * 因为数据有正负，所以我们要分别记录最大值，和最小值
 * 然后让当前值和最大值以及最小值分别相乘，再取最大
 * 同时maxPre minPre要分别更新为当前最大最小
 *
 * */
int maxProduct(vector<int> &nums){
    if (nums.size() < 1)
        return 0;
    int maxPre = nums[0];  // 记录前一步最大值
    int minPre = nums[0];  // 记录前一步最小值
    int res = nums[0];     // 记录全局最大值

    int maxCur, minCur;    // 记录当前最大最小值
    for (int i=1; i<nums.size(); i++){
        maxCur = max(max(nums[i] * maxPre, nums[i] * minPre), nums[i]);
        minCur = min(min(nums[i] * maxPre, nums[i] * minPre), nums[i]); // 如果没有maxHere，此时的maxCur是上一步更新之后的
        res = max(maxCur, res);
//        res = max(max(maxCur, minCur), res);
        maxPre = maxCur;
        minPre = minCur;
    }
    return res;
}

int main(){
    int arr[] = {-4, -3, -2};
    vector<int> nums(arr, arr+ sizeof(arr)/ sizeof(arr[0]));
    cout<<maxProduct(nums)<<endl;
    return 0;
}