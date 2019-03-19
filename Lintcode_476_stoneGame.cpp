//
// Created by greg on 19-3-19.
//

#include <iostream>
#include <vector>
using namespace std;


/**
 * https://blog.csdn.net/gatieme/article/details/49206193
 * 石子合并
 *
 * */
int stoneGame(vector<int> &A){
    if (A.size() < 1)
        return 0;

    vector<int> sum(A.size(), 0);
    sum[0] = A[0];
    for (int i=1; i<A.size(); i++)
        sum[i] = sum[i-1] + A[i];

    vector<vector<int>> dp(A.size(), vector<int>(A.size(), 0));

    for (int v=1; v<A.size(); v++){
        for (int i=0; i<A.size()-v; i++){
            int j = i + v;
            dp[i][j] = INT8_MAX;
            int tmp = sum[j] - (i > 0 ? sum[i-1] : 0);
            for (int k=i; k<j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + tmp);
            }

        }
    }
    return dp[0][A.size()-1];
}

int main(){
    int arr[] = {4, 1, 1, 4};
    vector<int> A(arr, arr + sizeof(arr)/ sizeof(arr[0]));
    cout<<stoneGame(A)<<endl;

    return 0;
}