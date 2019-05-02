//
// Created by greg on 19-5-2.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

/**
 * https://www.lintcode.com/problem/longest-substring-without-repeating-characters/description
 * 获得数组中最长不重复子串的长度
 * 输入：abcabcbba 输出 3
 * 利用map记录数组中不重复字符出现的位置，map相当于python中的set。
 * lastPos记录这个字符上次出现的位置，如果没出现过lastPos=-1
 * 当第二次找到这个字符时，从map中获得上次出现的位置索引，与当前位置的索引做差即可获得长度
 * */
int lengthOfLongestSubstring(string &s){
    if (s.size() < 2)
        return s.size();

    map<char, int> m;
    int maxLength = 0, lastPos = -1;
    for (int i=0; i<s.size(); i++){
        if (m.find(s[i]) != m.end() && m[s[i]] > lastPos)
            lastPos = m[s[i]];
        if (i - lastPos > maxLength)
            maxLength = i - lastPos;

        m[s[i]] = i;
    }

    return maxLength;
}

/**
 * 做法同上面一样，&& lastPos < tmp[s[i]]这句话很关键，如果没有这句话输入s2得到的结果就是9
 * 因为lastPos记录的是以i为结尾的字符串中，重复字符最后一次出现的索引。
 * 当i指到最后一个'a'时，如果有lastPos < tmp[i]这个判断存在，tmp[s[i]]=0, 而lastPos=4(第一个'-'的位置)
 * 这时是不满足条件的，因此lastPos不需要更新。因为如果更新的话就忽略了中间其它字符出现重复的问题。
 * */
int lengthOfLongestSubstring1(string &s){
    if (s.size() < 2)
        return s.size();

    vector<int> tmp(256, -1);
    int maxLength = 0, lastPos = -1;
    for (int i=0; i<s.size(); i++){
        if (tmp[s[i]] != -1 && lastPos < tmp[s[i]])
            lastPos = tmp[s[i]];
        if (i - lastPos > maxLength)
            maxLength = i - lastPos;

        tmp[s[i]] = i;
    }

    return maxLength;
}

int main(){
//    string s1 = "abcabcabb";
//    cout<<lengthOfLongestSubstring(s1)<<endl;
//    cout<<lengthOfLongestSubstring1(s1)<<endl;

    string s2 = "an++--viaj";
    cout<<lengthOfLongestSubstring(s2)<<endl;
    cout<<lengthOfLongestSubstring1(s2)<<endl;

    return 0;
}