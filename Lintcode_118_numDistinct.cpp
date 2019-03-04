//
// Created by greg on 19-3-4.
//
#include <iostream>
#include <vector>
using namespace std;


/**
 * 不同的子序列
 * 给出字符串S和字符串T，计算S的不同的子序列中T出现的个数。
 * 子序列字符串是原始字符串通过删除一些(或零个)产生的一个新的字符串，并且对剩下的字符的相对位置没有影响。
 * (比如，“ACE”是“ABCDE”的子序列字符串,而“AEC”不是)。
 * 给出S = "rabbbit", T = "rabbit"
 * 返回 3
 *
 * 动态规划，定义一个dp[][]数组，dp[i][j]表示字符以S[i-1]为结尾的字符串变为以T[j-1]结尾的字符串有几种方式
 * 当S[i-1]==T[i-1] 我们要考虑dp[i-1][j-1]以及dp[i-1][j]两个位置的值，
 * dp[i-1][j-1]表示S[i-2]变为T[j-2]有几种方式，
 * dp[i-1][j]表示S[i-2]变为T[j-1]有几种方式
 *
 * 如果不相等，dp[i][j]只能继承S[i-2]变为T[j-1]有几种方式
 *
 * 看矩阵图比较清晰
 *
 * */
int numDistinct(string &S, string &T) {
    // write your code here
    vector<vector<int>> dp(S.size()+1, vector<int>(T.size()+1, 0));
    for (size_t i=0; i<S.size()+1; i++)
        dp[i][0] = 1;

    for (size_t i=1; i<=S.size(); i++){
        for (size_t j=1; j<=T.size(); j++){
            if (S[i-1]==T[j-1])
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    for (auto vec : dp){
        for (auto num : vec)
            cout<<num<<" ";
        cout<<endl;
    }

    return dp[S.size()][T.size()];
}

int main(){
    string S = "rabbbit";
    string T = "rabit";
    cout<<numDistinct(S, T)<<endl;

    return 0;
}
