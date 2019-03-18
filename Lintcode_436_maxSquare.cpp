//
// Created by greg on 19-3-18.
//
#include <iostream>
#include <vector>
using namespace std;


/**
 * 在一个二维01矩阵中找到全为1的最大正方形, 返回它的面积.
 *
 * 采用动态规划的方式，第一行和第一列的数字只能生成最大边长为１的正方形
 * 如果一个点能够成为一个正方形的右下角，那么它的左上角　左方　上方三个位置应该都有才可以，因此应该取三个数字
 * 中的最小再加一，此时记录的是最长的边长。
 *
 *
 * */
int maxSquare(vector<vector<int>> &matrix){
    if (matrix.size() < 1)
        return 0;

    size_t row = matrix.size(), col = matrix[0].size();
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));

    for (size_t i=0; i<row; i++){
        if (matrix[i][0]==1)
            dp[i][0] = 1;
    }

    for (size_t i=0; i<col; i++){
        if (matrix[0][i]==1)
            dp[0][i] = 1;
    }
    int res = 1;
    for (size_t i=1; i<row; i++){
        for (size_t j=1; j<col; j++){
            if (matrix[i][j]==1)
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
            res = res > dp[i][j] ? res : dp[i][j];
        }
    }

    return res * res;
}

int main(){
    vector<int> tmp;
    vector<vector<int>> matrix;
    tmp.push_back(1), tmp.push_back(0), tmp.push_back(1), tmp.push_back(0), tmp.push_back(0);
    matrix.push_back(tmp);

    tmp.clear();
    tmp.push_back(1), tmp.push_back(0), tmp.push_back(1), tmp.push_back(1), tmp.push_back(1);
    matrix.push_back(tmp);

    tmp.clear();
    tmp.push_back(1), tmp.push_back(1), tmp.push_back(1), tmp.push_back(1), tmp.push_back(1);
    matrix.push_back(tmp);

    tmp.clear();
    tmp.push_back(1), tmp.push_back(0), tmp.push_back(0), tmp.push_back(1), tmp.push_back(0);
    matrix.push_back(tmp);

    cout<<maxSquare(matrix)<<endl;


    return 0;
}
