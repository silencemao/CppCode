//
// Created by greg on 19-3-5.
//

#include <iostream>
#include <vector>
using namespace std;


/**
 * 编辑距离
 * 给出两个单词word1和word2，计算出将word1 转换为word2的最少操作次数。
 * 你总共三种操作方法：
 * 插入一个字符　　删除一个字符　替换一个字符
 * 给出 work1="mart" 和 work2="karma"
 * 返回 3
 *
 *
 * */
int minDistance(string &word1, string &word2){
    vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));
    for (int i=0; i<word1.size()+1; i++)  // 填充第一列
        dp[i][0] = i;
    for (int j=0; j<word2.size()+1; j++)  // 填充第二列
        dp[0][j] = j;

    for (size_t i=1; i<word1.size()+1; i++){
        for (size_t j=1; j<word2.size()+1; j++){
            if (word1[i-1]==word2[j-1])   // 如果当前字符相等，则需要考虑从头至当前前一个位置需要改变的次数
                dp[i][j] = dp[i-1][j-1];
            else                    // 替换       删除         插入
                dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
        }
    }
    return dp[word1.size()][word2.size()];
}

int main(){

    string word1 = "mart";
    string word2 = "karma";

    cout<<minDistance(word1, word2)<<endl;
    return 0;
}