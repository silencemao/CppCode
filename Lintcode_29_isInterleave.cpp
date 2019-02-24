//
// Created by greg on 18-10-29.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 * 交叉字符串，给定两个字符串s1和s2，以及字符串s3，判断s3是否可以由s1和s2交叉组成。
 * 比如 s1 = "aabcc" s2 = "dbbca"
 * - 当 s3 = "aadbbcbcac"，返回  true.
 * - 当 s3 = "aadbbbaccc"， 返回 false.
 * 采用动态规划的方式，用一个二维数组记录当前s1[i],s2[j]位置前面的字符是否可以组成s3[i+h-1]前面的字符串
 * 首先初始化数组，大小[m+１][n+1]
 * 接着查看只用s1或者只用s2是否可以组成s3，此时已经把二维数组的第一行和第一列完成
 * 接着两个for循环，res[i-1][j]==1代表s1[i]前面(不包括当前位置)和s2[j]前面(不包括)的字符可以组成s3[i+j-1]前面(不包括)的字符串
 * 如果res[i-1][j]==1并且　s1[i-1]==s3[i+j-1]，则说明加上s1[i-1]可以组成s3[0]至s3[i+j-1]之间的字符
 * res[i][j-1]同上
 * */

bool isInterleave(string &s1, string &s2, string &s3) {
    size_t m = s1.length(), n = s2.length();
    if (m+n != s3.length())
        return false;
    vector<vector<bool>> res(m+1, vector<bool>(n+1, false));
    res[0][0] = true;
    int i = 1, j = 1;
    while (i <= m && s1[i-1]==s3[i-1])
        res[i++][0] = true;

    while (j <= n && s2[j-1]==s3[j-1])
        res[0][j++] = true;

    for (i=1; i<=m; i++){
        for (j=1; j<=n; j++){
            if ((res[i-1][j] && s1[i-1]==s3[i+j-1]) || (res[i][j-1] && s2[j-1]==s3[i+j-1]))
                res[i][j] = true;
        }
    }
    return res[m][n];
}

int main(){
    string s1 = "aabcc", s2 = "dbbca";
    string s3 = "aadbbbaccc";
    cout<<isInterleave(s1, s2, s3)<<endl;

}