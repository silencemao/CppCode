//
// Created by greg on 19-4-15.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 * 整数拆分
 * 给定一个正整数 n ，将其拆分成至少两个正整数之和，并且使这些整数之积最大。返回这个最大乘积。
 * */
int integerBreak(int n){
    vector<int> dp(n+1, 1);
    for (int i=2; i<=n; i++){
        dp[i] = i;
        if (i==n) dp[i] = 0;
        for (int j=1; j<i; j++){
            dp[i] = max(dp[i], dp[i-j] * j);
        }
    }
    return dp.back();
}

/**
 * 最终所有的数据都会拆分程2 3 1的组合，
 * */
int integerBreak1(int n){
    vector<int> dp(n+1, 0);
    dp[0] = 0, dp[1] = 1, dp[2] = 1, dp[3] = 2;
    for (int i=4; i<=n; i++){
        int tmp1 = max(dp[i-2]*2, 2*(i-2));
        int tmp2 = max(dp[i-3]*3, 3*(i-3));
        dp[i] = max(tmp1, tmp2);
    }
    return dp.back();
}

int main(){
    for (int i=1; i<14; i++){
        cout<<(integerBreak(i)==integerBreak1(i))<<endl;
    }

//    cout<<integerBreak1(n)<<endl;

    return 0;
}