//
// Created by greg on 19-3-25.
//
#include <iostream>
#include <vector>

using namespace std;

/**
 * 解码方法，
 * 'A' 1
 * 'B' 2
 * 'Z' 26
 *
 * 给定一个数字字符串，求出有几种解码方法
 *
 * http://www.cnblogs.com/grandyang/p/4313384.html
 * */
int numDecodings(string &s){
    if (s.size() < 1)
        return 0;

    vector<int> dp(s.size()+1, 0);
    dp[0] = 1;
    for (int i=1; i<=s.size(); i++){  // i-1代表字符的位置
        dp[i] = (s[i-1]=='0') ? 0 : dp[i-1];  // 若当前位置为0，则有０种组合　否则和前一个位置的组合数相等
        if (i > 1 && (s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<='6'))) // 再判断当前位置和前一个位置一起的组合结果
            dp[i] += dp[i-2];
    }
    return dp.back();
}


int numDecodings1(string &s){
    if (s.empty() || s.front()==0)
        return 0;

    int c1 = 1, c2 = 1;
    for (int i=1; i<s.size(); i++){
        if (s[i]=='0') c1 = 0;
        if (s[i-1]=='1' || (s[i-1]=='2' && s[i] <= '6')){
            c1 = c1 + c2;
            c2 = c1 - c2;
        }
        else
            c2 = c1;

    }

    return c1;
}

int main(){
    string a = "123";

    cout<<numDecodings(a)<<endl;
    cout<<numDecodings1(a)<<endl;
    return 0;
}
