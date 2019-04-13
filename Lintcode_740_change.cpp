//
// Created by greg on 19-4-13.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 * 零钱兑换，给定一个数字amount和一个数组coins[]，判断数组中的数字有几种组合可以构成amount，
 * 数组中的数字可以重复使用
 *
 * dfs会超时
 * */
void dfs(int &res, vector<int> &cur, vector<int> coins, int target, int index){
    if (target < 0)
        return;

    if (target==0){
        res += 1;
        return;
    }

    for (int i=index; i<coins.size(); i++){
        if (coins[i] <= target){
            cur.push_back(coins[i]);
            dfs(res, cur, coins, target-coins[i], i);
            cur.pop_back();
        }
        else
            break;
    }
}

int change(int amount, vector<int> &coins){
    if (amount < 1)
        return 0;

    int res;
    vector<int> cur;
    dfs(res, cur, coins, amount, 0);
//    for (auto vec : res){
//        for (auto num : vec)
//            cout<<num<<" ";
//        cout<<endl;
//    }
    return res;
}

/**
 * 二维dp
 * https://blog.csdn.net/zxzxzx0119/article/details/81275479
 * */
int change1(int amount, vector<int> &coins){
    if (amount==0)
        return 1;
    if (amount < 0 || coins.size() < 1)
        return 0;

    vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 0));
    dp[coins.size()][0] = 1;

    for (int i=coins.size()-1; i>=0; i--){
        for (int j=0; j<=amount; j++)
            /**
             *  j>=coins[i]时，dp[i][j-coins[i]]表示j腾出coins[i]空间时的组成个数
             *  dp[i+1][j]表示其它数字组成j的方法数
             */

            dp[i][j] = j >= coins[i] ? dp[i][j-coins[i]] + dp[i+1][j] : dp[i+1][j];
    }

    for (auto vec : dp){
        for(auto num : vec)
            cout<<num<<" ";
        cout<<endl;
    }
    return dp[0][amount];
}



int main(){
    int arr[] = {2, 3, 8};
    int amount = 8;
    vector<int> coins(arr, arr+ sizeof(arr)/ sizeof(arr[0]));
    cout<<change1(amount, coins)<<endl;
    return 0;
}