//
// Created by greg on 19-4-12.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 * 切割绳子，
 * 给一个 n 英寸长的杆子和一个包含所有小于 n 的尺寸的价格. 确定通过切割杆并销售碎片可获得的最大值.
 * */
int cutting(vector<int> &prices, int n) {
    // Write your code here
    if (n < 1)
        return 0;
    vector<int> dp(n+1, 0);
    for (int i=1; i<=n; i++){     // 记录以i长度为结尾的绳子切割取得的最大数值
        for (int j=0; j<i; j++){  // i长度的绳子可以切割成0-i之间的任意数，
            dp[i] = max(dp[i], dp[j] + prices[i-j-1]);
        }
    }

//    for (int i=0; i<n; i++){
//        for (int j=i+1; j<=n; j++){
//            dp[j] = max(dp[j], dp[j-i-1]+prices[i]);
//        }
//    }
    return dp[n];
}

int main(){
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;
    vector<int> prices(arr, arr+ sizeof(arr)/ sizeof(arr[0]));
    cout<<cutting(prices, n)<<endl;
    return 0;
}