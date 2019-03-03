//
// Created by greg on 19-3-3.
//
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * 单词拆分，	输入:  "lintcode", ["lint", "code"]
	输出:  true

	输入: "a", ["a"]
	输出:  true

 　采用动态规划的方式，dp[i]记录以i为结尾时，s(j, i-j)的字符串是否在dict中，



 * */
bool wordBreak(string &s, unordered_set<string> &dict) {
    // write your code here
    if (s.size()==0 && dict.size()==0)
        return false;

    vector<bool> dp(s.size()+1, false);
    dp[0] = true;
    for (int i=1; i<=s.size(); i++){
        for (int j=i-1; j>=0; j--){
            string word = s.substr(j, i-j);  // 从j开始取，取i-j个字符
            if (dp[j] && (dict.find(word)!=dict.end())){
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}

int main(){
    string s = "lintcode";
    unordered_set<string> dict = {"lint", "code"};
    cout<<wordBreak(s, dict)<<endl;
    cout<<s.substr(1, 1)<<endl;

    return 0;
}
