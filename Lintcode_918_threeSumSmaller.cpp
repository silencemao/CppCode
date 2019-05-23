//
// Created by greg on 19-5-21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 三数之和，从数组中找到三个数字，使其满足nums[i]+nums[j]+nums[k]<target，并且i<j<k
 * 返回这样组合的个数
 *
 * 其实i<j<k不是什么条件，最开始因为这个条件使我不敢对数组排序，后来发现，只要三个数不是取得相同位置的就可以了。
 * 以[-2, -1, 0, 3]为例，重点讲一下 result += right - left
 * i=0 left=1 right=3 [-2, 1, 3]满足条件，left++
 * i=0, left=2, right=3 [-2, 0, 3]满足条件　left++
 * i=0, left=3 退出循环
 * i=1 left=2 right=3 不满足条件，这样得到的结果只有两个，实际上正确答案是三个
 *
 * */
int threeSumSmaller(vector<int> &nums, int target){
    int result = 0;
    sort(nums.begin(), nums.end());
    int len = nums.size();
    // cout<<(nums.size() - 2)<<endl;   // 这个数无限大
    for (int i=0; i<len-2; i++){  // 此处用nums.size()-2就会陷入死循环
        int left = i+1, right = nums.size() - 1;
        while (left < right){
            if ((nums[i] + nums[left] + nums[right]) < target){
                result += right - left;   //  此处如果写result += 1就不对
                left++;
            }
            else
                right--;
        }
    }
    return result;
}

int main(){
    int arr[] = {-2, 0, 1, 3};
    vector<int> nums;

    cout<<nums.size()<<endl;
    cout<<(nums.size()-2)<<endl;  // 很诡异

    cout<<threeSumSmaller(nums, 2)<<endl;

    return 0;
}