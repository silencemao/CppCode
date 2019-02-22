//
// Created by greg on 19-2-22.
//
#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
    // write your code here
    vector<vector<int>> res(m, vector<int>(n, 1));
    if (m==1 || n==1)
        return 1;

    for (size_t i=1; i<m; i++){
        for (size_t j=1; j<n; j++){
            res[i][j] = res[i-1][j] + res[i][j-1];
        }
    }
    return res[m-1][n-1];
}

int main(){
    int m = 1, n = 3;
    cout<<uniquePaths(m, n)<<endl;

    return 0;
}