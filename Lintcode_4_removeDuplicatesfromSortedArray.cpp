//
// Created by greg on 17-9-24.
// vector<int> nums 和 vector<int> nums[10];有什么区别
//输入：排序后的数组。输出：去除数组中相同的元素，数组的长度。
//
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums){
    int count = 0;
    for (int i=1; i<nums.size(); i++){
        if (nums[i] == nums[i-1]){
            count ++;
        }else{
            nums[i-count] = nums[i];
        }
    }
    return int(nums.size() - count);
}

int main(){
    vector<int> nums;
    for (int i=0; i<5; i++){
        nums.push_back(i);
        nums.push_back(i+1);
    }
    cout<<nums.size()<<endl;
    int a = removeDuplicates(nums);
    cout<<a<<endl;


    vector<int> nums1[5];
    for (int i=0; i<nums1->size(); i++){
        nums1->push_back(i);
    }
    cout<<nums1->size();

    return 0;
}

