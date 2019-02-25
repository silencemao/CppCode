//
// Created by greg on 19-2-25.
//

#include <iostream>
#include <vector>
using namespace std;


/**
 *
 * 最长上升子序列，给定一段数组，找出数组中最长的上升子序列，这个子序列不宜电感是连续的。
 * 	输入:  [5,4,1,2,3]
	输出:  3
	LIS 是 [1,2,3]
 *
 * 采用动态规划的方式，定义一个长度与输入数组长度一致的数组res
 * res中每一个位置存储的是以当前位置为结尾的最长上升子序列的长度，若要获得以当前位置为结尾的最长子序列的长度，我们就要比较
 * 当前位置与前面每一个位置的大小比较得出
 * */

int longestIncreasingSubsequence(vector<int> &nums) {
    // write your code here
    if (nums.size()<1)
        return 0;
    size_t size = nums.size();
    vector<int> res(size, 1);
    int maxL = 1;
    for (size_t i=1; i<size; i++){
        for (size_t j=0; j<i; j++){
            if (nums[i] > nums[j]){
                res[i] = max(res[j]+1, res[i]);
                maxL = max(maxL, res[i]);
            }
        }
    }
    return maxL;
}


/**
 * https://blog.csdn.net/wbin233/article/details/77570070
 *
 * 贪心 + 二分法
 * 维护一个数组
 *
 */

int longestIncreasingSubsequence1(vector<int> &nums){
    if (nums.size() < 1)
        return 0;
    size_t size = nums.size();
    int dp[size];
    for (size_t i=0; i<size; i++)
        dp[i] = INT32_MAX;
    dp[0] = nums[0];
    int pos = 0;

    for (size_t i=1; i<size; i++){
        if (nums[i] > dp[pos])
            dp[++pos] = nums[i];
        else //  // 否则找到dp中第一个大于等于a[i]的位置，用a[i]替换之。
            dp[lower_bound(dp, dp+pos+1, nums[i])-dp] = nums[i];
    }
    return pos+1;
}

int main(){
    int arr[] = {9, 3, 6, 2, 7};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
    cout<<longestIncreasingSubsequence1(nums)<<endl;

    return 0;
}

