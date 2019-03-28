//
// Created by greg on 19-3-28.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 * 环形房屋打劫
 * 不能打劫相邻的两间屋子
 * 计算0-(n-1) 和　1-(n)两个子序列的大小
 * */
int helper(vector<int> &nums, int begin, int end){
    if (end - begin==1)
        return max(nums[begin], nums[end]);

    int pre = nums[begin];
    int cur = max(nums[begin], nums[begin+1]);

    for (int i=begin+2; i<=end; i++){
        int tmp = max(pre + nums[i], cur);
        pre = cur;
        cur = tmp;
    }

    return cur;
}

int houseRobber2(vector<int> &nums) {
    // write your code here
    if (nums.size() < 1)
        return 0;
    size_t size = nums.size();
    if (size==1)
        return nums[0];
    if (size==2)
        return max(nums[0], nums[1]);

    int first = helper(nums, 0, size-2);
    int second = helper(nums, 1, size-1);
    return first > second ? first : second;
}

int main(){
    int arr[] = {2, 3, 2, 3};
    vector<int> nums(arr, arr+ sizeof(arr)/ sizeof(arr[0]));
    cout<<houseRobber2(nums);

    return 0;
}