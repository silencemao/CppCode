//
// Created by greg on 19-5-29.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/**
 * 四数之和
 * https://www.lintcode.com/problem/4sum/description
 * */
vector<vector<int>> fourSum(vector<int> &nums, int target){
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int left, right;
    int length = nums.size();
    for (int i=0; i<length-3; i++){
        if (i && nums[i]==nums[i-1])
            continue;
        for (int j=i+1; j<length-2; j++){
            if (j!=i+1 && nums[j]==nums[j-1])
                continue;
            left = j+1;
            right = length-1;
            vector<int> tmp;
            while (left < right){
                if (nums[i] + nums[j] + nums[left] + nums[right]==target){
                    tmp.clear();
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[left]);
                    tmp.push_back(nums[right]);
                    res.push_back(tmp);
                    left++;
                    right--;
                    while (left < right && nums[left]==nums[left-1])
                        left++;
                    while (left < right && nums[right]==nums[right+1])
                        right--;
                }
                else if (nums[i] + nums[j] + nums[left] + nums[right] < target)
                    left++;
                else
                    right--;
            }
        }
    }
    return res;
}

int main(){
    int arr[] = {-2,-3,-4,-5,-100,99,1,4,4,4,5,1,0,-1,2,3,4,5};
    vector<int> nums(arr, arr+ sizeof(arr)/ sizeof(arr[0]));
    int target = 0;
    vector<vector<int>> res = fourSum(nums, target);
    for (auto vec : res){
        for (auto num : vec)
            cout<<num<<" ";
        cout<<endl;
    }
    return 0;
}
