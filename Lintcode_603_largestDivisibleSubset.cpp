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

/**
 * 数组中最大整除子集的长度，
 * 给定一个数组，从中找出一段子集，满足子集里面的数能够两两相互整除
 *
 * 最初的思路（错误的）：以为是普通的动态规划，定义一个和原始数组一样长度的数组，然后每一个位置记录以当前位置为结尾的最大整除子集的长度
 * 　　　　　　　　　　　如果num[i+1] % num[i]==0　则在i+1位置加１即可，这样是错误的思路，以数组1, 2, 3, 4, 6, 12为例，
 * 　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　dp 1, 2, 2, 3, 3, 4 如果按照上面的思路
 * 最后得到的结果应该是最大长度为６，但是实际结果为４。 当nums[i]=12时，num[i] % nums[0]、nums[1]、nums[2]都能整除，dp[2]=2,此时dp[5]=3
 * dp[2]+1 = dp[5] nums[5]能整除num[2] 但是dp[2]+1=dp[5]，说明在i=2前面的数中有nums[2]不能整除但是nums[5]能整除的数，所以此时
 * dp[i] = max(dp[i], dp[j]) + 1是不对的，这样就默认前面的数nums[j]全部能整除，因此下面屏蔽的代码是不对的。
 * */
int largestDivisibleSubset1(vector<int> &nums){
    if (nums.size() < 1)
        return {};
    sort(nums.begin(), nums.end());
    vector<int> dp(nums.size(), 0);
    dp[0] = 1;
    int res = 1;
    for (int i=1; i<nums.size(); i++){
        for (int j=0; j<i; j++){
//            错误的写法
//            if (nums[i] % nums[j]==0)
//                dp[i] = max(dp[i], dp[j]) + 1;

            if (nums[i] % nums[j]==0 && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
        res = res > dp[i] ? res : dp[i];
    }
    cout<<res<<endl;
}

int main(){

    int arr[] = {1, 2, 3, 4, 6, 12};
    vector<int> nums(arr, arr+ sizeof(arr)/ sizeof(arr[0]));
    largestDivisibleSubset1(nums);
//    vector<int> res = largestDivisibleSubset(nums);
//    for (auto num : res)
//        cout<<num<<" ";
//    cout<<endl;

    return 0;
}