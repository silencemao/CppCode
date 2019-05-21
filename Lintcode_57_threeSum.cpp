//
// Created by greg on 19-5-21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * https://www.lintcode.com/problem/3sum/description
 * 三数之和，给定一个数组之后，取出数组中三个数字的组合，使这三个数字的和为0
 * */
vector<vector<int>> threeSum(vector<int> &nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for (int i=0; i<nums.size()-1; i++){
        if (i > 0 && nums[i]==nums[i-1])
            continue;

        int left = i+1, right = nums.size()-1;
        while (left < right){
            vector<int> tmp;

            int sumOfThree = nums[i] + nums[left] + nums[right];
            if (sumOfThree==0){

                tmp.push_back(nums[i]);
                tmp.push_back(nums[left]);
                tmp.push_back(nums[right]);

                result.push_back(tmp);

                while (left < right && nums[left]==nums[left+1])
                    left += 1;

                while (left < right && nums[right]==nums[right-1])
                    right -= 1;

                left += 1;
                right -= 1;
            }
            else if (sumOfThree > 0){
                while (right > 0 && nums[right]==nums[right-1])
                    right--;
                right--;
            }
            else if (sumOfThree < 0){
                while (left < nums.size()-1 && nums[left]==nums[left+1])
                    left++;
                left++;
            }

        }
    }
    return result;
}

int main(){
    int arr[] = {-1, 0, 1, 2, -1, 4};
    vector<int> nums(arr, arr+ sizeof(arr)/ sizeof(arr[0]));
    vector<vector<int>> result = threeSum(nums);
    for (auto vec : result){
        for (auto num : vec)
            cout<<num<<" ";
        cout<<endl;
    }
    return 0;
}