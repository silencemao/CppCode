//
// Created by greg on 19-2-26.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 * 给出两个字符串，找到最长公共子序列(LCS)，返回LCS的长度。
 *最长公共子序列问题是在一组序列（通常2个）中找到最长公共子序列（注意：不同于子串，LCS不需要是连续的子串）。
 * 该问题是典型的计算机科学问题，是文件差异比较程序的基础，在生物信息学中也有所应用。
 *
 * */
int longestCommonSubsequence(string &A, string &B) {
    // write your code here
    if (A.size() < 1 || B.size() < 1)
        return 0;

    size_t m = A.size(), n = B.size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (size_t i=0; i<m; i++){
        if (A[i]==B[0])
            dp[i][0] = 1;
        else{
            if (i > 0)
              dp[i][0] = dp[i-1][0];
        }
     }


    for (size_t j=0; j<n; j++){
        if (A[0]==B[j])

            dp[0][j] = 1;
        else {
            if (j > 0)
                dp[0][j] = dp[0][j-1];
        }
    }


    for (size_t i=1; i<m; i++){
        for (size_t j=1; j<n; j++){
            if (A[i]==B[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<"  ";
    for (char c : B)
        cout<<c<<" ";
    cout<<endl;

    for (size_t i=0; i<m; i++){
        cout<<A[i]<<" ";
        for (size_t j=0; j<n; j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }

    return dp[m-1][n-1];
}

int longestCommonSubsequence1(string &A, string &B){
    if (A.size() < 1 || B.size() < 1)
        return 0;
    size_t m = A.size(), n = B.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (size_t i=0; i<m; i++){
        for (size_t j=0; j<n; j++){
            // 此处要注意，当A[i]==B[j]时，我们要看dp[i-1][j-1]位置的值，不能取max(dp[i-1][j],dp[i][j-1])的值
            // 如果取了dp[i-1][j]的值，相当于B[j]多参与了一次比较，取dp[i][j-1]同理
            if (A[i]==B[j])
                dp[i+1][j+1] = dp[i][j] + 1;
            else
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    }


    cout<<"    ";
    for (char c : B)
        cout<<c<<" ";
    cout<<endl;

    for (size_t i=0; i<=m; i++){
        cout<<A[i-1]<<" ";
        for (size_t j=0; j<=n; j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }

    return dp[m][n];
}

int main(){
    string A = "bedaacbade";
    string B = "dccaeedbeb";

    cout<<longestCommonSubsequence1(A, B)<<endl;
    return 0;
}