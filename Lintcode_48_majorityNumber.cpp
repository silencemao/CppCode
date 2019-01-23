//
// Created by greg on 18-11-19.
//
#include <iostream>
#include <vector>
using namespace std;

// https://blog.csdn.net/surp2011/article/details/51202354

/**
 * 主元素１，数组中出现次数超过一半的数字
 * */
int majorityNumber(vector<int> &nums){
    if (nums.size()<1)
        return -1;
    int res = nums[0], count = 1;
    for (int i=1; i<nums.size(); i++){
        if (nums[i]==res)
            count++;
        else {
            if (count > 0)
                count--;
            else{
                res = nums[i];
                count = 1;
            }
        }
    }

    return res;
}
/**
 * 数组中出现次数严格大于数组个数1/3的元素
 * */
int majorityNumber2(vector<int> &nums){
    if (nums.size()<1)
        return -1;
    int majorityNum1 = nums[0], count1 = 1;
    int majorityNum2 = nums[1], count2 = 1;

    for (int i=2; i<nums.size(); i++){
        if (nums[i]==majorityNum1)
            count1++;
        else if (nums[i]==majorityNum2)
            count2++;
        else if (count1==0){
            majorityNum1 = nums[i];
            count1++;
        }
        else if (count2==0){
            majorityNum2 = nums[i];
            count2++;
        }
        else{
            count1--;
            count2--;
        }
    }

    count1 = count2 = 0;
    for (int i=0; i<nums.size(); i++){
        if (nums[i] == majorityNum1)
            count1++;
        else if (nums[i] == majorityNum2)
            count2++;
    }

    // 这种写法是数组中一定存在一个数，它的个数大于数组长度的1/3
    // 真实环境中应该验证一下才行
    return count1 > count2 ? majorityNum1 : majorityNum2;
}

/**
 * 给定一个数组和一个数字k,找出数组中数字个数严格大于数组长度的1/k的数字
 *
 * 找到个数严格大于数组长度1/k的数字，以K=3为例，当其中两个数的个数都大于1/3时，并且二者之和小于1
 *
 * 我们只统计其中最多的两个数即可，因为第三个数的个数是少于1/3的，用递减法统计完也是负数。
 *
 * 我们此处只需要统计其中k-1个数的个数即可。
 * 首先利用一个tmp数组保存候选数字，count数组统计候选数字的个数
 * 接着遍历数组，判断数字是否为为候选数组中数字，
 * 　　如果是候选数组中的，我们直接将候选数字对应的计数count+1，
 * 　　hasUsed用于数组中的数字是否为被记录过，当他和候选数组中的数字相等时，count+1之后要把hasUsed设置为true，因为tmp后面的不需要判断了
 * 　　然后直接结束当前循环，判断下一个数字
 *
 * 　　如果当前数字num[i]不是候选数组中的数字，并且候选数组中有的计数仍为0,我们直接设置该候选位置为当前数字num[i]，同时count+1此时的
 * 　　hasUsed和上一步的效果一样
 *
 * 　　如果当前数字既不在候选数组tmp中，并且count数组中候选数字的个数都不为0，则直接将所有候选数字的计数全部减一
 *
 * 　　最后再把候选数组中的数字个数都统计一遍，取最大的输出
 *
 *
 * */
int majorityNumber3(vector<int> &nums, int k){

    if (nums.size() < 1 || k < 1)
        return -1;

    vector<int> tmp(k-1, 0);
    vector<int> count(k-1, 0);

    for (int i=0; i<nums.size(); i++){  // 遍历每一个元素
        bool hasUsed = false;
        for (int j=0; j<k-1; j++){      // 如果当前元素在tmp中，对应位置加１，然后直接结束本次循环以及外层循环，进行下一次大循环(判断下一个数)
            if (nums[i] == tmp[j]){
                count[j]++;
                hasUsed = true;
                break;
            }
        }

        if (hasUsed)    // 结束最外层的当前循环
            continue;

        for (int j=0; j<k-1; j++){  // 当前元素不在tmp中
            if (count[j]==0){               // 如果有的主元素个数为0，更新主元素以及对应位置的值。退出循环
                tmp[j] = nums[i];
                count[j]++;
                hasUsed = true;
                break;
            }
        }

        if (hasUsed)
            continue;

        for (int j=0; j<k-1; j++)  // 当前元素即不在tmp中，而且count中的值也不为０，统统减一
            count[j]--;
    }

    for(int i=0; i<k-1; i++)
        count[i] = 0;
    for (int i=0; i<nums.size(); i++){
        for (int j=0; j<k-1; j++){
            if (nums[i]==tmp[j]){
                count[j]++;
                continue;
            }
        }
    }

    int index = 0;
    for (int j=1; j<k-1; j++){
        if (count[j] > count[index])
            index = j;
    }
    return tmp[index];
}

int majorityNumber4(vector<int> &nums, int k){
    if (nums.size() < 1 || k < 1)
        return -1;

    vector<int> tmp(k-1, 0);
    vector<int> count(k-1, 0);

    for (int i=0; i<nums.size(); i++){
        bool hasUsed = false;
        for (int j=0; j<k-1; j++){
            if (nums[i]==tmp[j]){
                count[j]++;
                hasUsed = true;
                break;
            }
        }

        if (hasUsed)
            continue;

        for (int j=0; j<k-1; j++){
            if (count[j]==0){
                tmp[j] = nums[i];
                count[j]++;
                hasUsed = true;
                break;
            }
        }

        if (hasUsed)
            continue;

        for (int j=0; j<k-1; j++)
            count[j]--;
    }


    for (int i=0; i<k-1; i++)
        count[i] = 0;

    for (int i=0; i<nums.size(); i++){
        for (int j=0; j<k-1; j++){
            if (nums[i]==tmp[j]){
                count[j]++;
                continue;
            }

        }
    }

    int index = 0;
    for (int i=1; i<k-1; i++){
        if (count[i] > count[index])
            index = i;
    }

    return tmp[index];
}

int main(){

    int arr[] = {2, 2, 2, 1, 1, 1, 2, 0, 0, 5};
    vector<int> nums(arr, arr + sizeof(arr)/ sizeof(int));
//    int res = majorityNumber(nums);
//    cout<<res<<endl;

//    int res = majorityNumber2(nums);
//    cout<<res<<endl;

    int res = majorityNumber4(nums, 3);
    cout<<res<<endl;
    return 0;
}


