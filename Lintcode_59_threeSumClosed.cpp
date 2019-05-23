//
// Created by greg on 19-5-23.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * https://www.lintcode.com/problem/3sum-closest/description
 * 给定一个数组和一个目标值，在数组中寻找三元组，使其和最接近target，返回三元组的和。
 *
 * */
int threeSumCLosest(vector<int> &nums, int target){
    sort(nums.begin(), nums.end());
    int diff = 0;    // 记录三元组的和
    for (int i=0; i<nums.size()-2; i++){
        int left = i+1从, right = nums.size()-1;  // 这个一定要放在while之外，否则陷入死循环
        while (left < right){

            int threeSum = nums[i] + nums[left] + nums[right];
            if (diff==0 || abs(threeSum-target) < abs(diff-target))
                diff = threeSum;

            if (threeSum < target)
                left += 1;
            else
                right -= 1;
        }
    }
    return diff;
}

int main(){
    int arr[] = {-1, 2, 1, -4};
    vector<int> nums(arr, arr+ sizeof(arr)/ sizeof(arr[0]));
    cout<<threeSumCLosest(nums, 0)<<endl;
    return 0;
}