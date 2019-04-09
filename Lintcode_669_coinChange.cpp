//
// Created by greg on 18-9-16.
//
#include <iostream>
#include <vector>

using namespace std;


/**
 * 最少用几个硬币来组合成amount
 * 动态规划，最少用几个数的和得到amount
 * 首先定义一个amount+1长度的数组，初始化为amount+1(最大)
 * 遍历每一个coins，计算j=coins[i]到amount的过程中，需要几个coins[i]
 * 用coins[i]来组合得到j，首先找到j-coins[i]位置的数（典型的背包问题）
 *
 * */

int coinChange(vector<int> &coins, int amount){
    vector<int> res(amount+1, amount+1);
    res[0] = 0;
    for (int i=0; i<coins.size(); i++){
        for (int j=coins[i]; j<=amount; j++)
            res[j] = min(res[j], res[j - coins[i]] + 1);
    }
    return res[amount]==amount+1 ? -1 : res[amount];
}

int main(){
    int arr[] = {2, 3, 5};
    int amount = 7;
    vector<int> coins(arr, arr+3);
    cout<<coinChange(coins, amount)<<endl;

    return 0;
}

