//
// Created by greg on 19-5-20.
//

#include <iostream>
#include <vector>

using namespace std;


/**
 * https://www.lintcode.com/problem/longest-common-prefix/description
 *
 * 最长公共前缀
 * */
string longestCommonPrefix(vector<string> &strs){
    if (strs.size() < 1)
        return "";

    if (strs.size()==1)
        return strs[0];

    string result = "";  //  先比较其中两个的前缀
    for (int i=0; i<min(strs[0].size(), strs[1].size()) && strs[0][i]==strs[1][i]; i++)
        result += strs[0][i];

    for (int i=2; i<strs.size(); i++){   // 然后利用这个前缀和其它的字符串对比
        for (int j=0; j<result.size(); j++){
            if (result[j]!=strs[i][j]){
                result = result.substr(0, j);
                break;
            }
        }
    }
    return result;
}

/**
 * https://github.com/haoel/leetcode/blob/master/algorithms/cpp/longestCommonPrefix/longestCommonPrefix.cpp
 * 从第一个字符串的第一个字符开始，和后面的每一个字符串对比
 * 如果第一个字符串取得子串长度大于后面字符串本身的长度　或者　取得子串和后面字符串取出来的结果不像等，则不匹配，准备输出
 *
 * 如果匹配，更新结果。
 *
 * */
string longestCommonPrefix1(vector<string> &strs){
    string result = "";
    if (strs.size() <= 0)
        return result;

    for (int i=1; i<=strs[0].size(); i++){
        string tmp = strs[0].substr(0, i);

        bool match = true;
        for (int j=1; j<strs.size(); j++){
            if (i > strs[j].size() || tmp != strs[j].substr(0, i)){
                match = false;
                break;
            }
        }

        if (!match){
            return result;
        }

        result = tmp;
    }
    return result;
}

/**
 * 思路同第一个
 * */
string help(string str1, string str2){
    if (str1.size()<1 || str2.size()<1)
        return "";
    string res = "";
    int i=0, j=0;
    while (i<str1.size() && j<str2.size()){
        if (str1[i] == str2[j]){
            res += str1[i];
            i++;
            j++;
        }
        else
            return res;
    }
    return res;
}

string longestCommonPrefix2(vector<string> &strs){
    if (strs.size()<1)
        return "";

    string res = strs[0];
    string tmp;
    if (strs.size() >= 2){
        tmp = help(strs[0], strs[1]);

        if (tmp.empty())
            return "";
    }

    for (int i=2; i<strs.size(); i++){
        tmp = help(tmp, strs[i]);
        res = res.size() < tmp.size() ? res : tmp;
    }
    return res;
}


int main(){
    vector<string> strs;
    strs.push_back("ABCDEFG");
//    strs.push_back("ABCEFG");
//    strs.push_back("ACEFA");
    cout<<longestCommonPrefix1(strs)<<endl;

    return 0;
}