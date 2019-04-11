//
// Created by greg on 19-4-11.
//


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int op_increase (int i) { return ++i; }
int op_sum (int i, int j) { return i+j; }

/**
 * 单词拆分
 * 给定一个字符串 CatMat
 * 给定一个字典　[Cat, Mat, Ca, tM, at, c, Dog, or, Do]
 * 计算字符串可以由字典中单词的组合构成
 * CatMat <= Cat Mat
 * CatMat <= Ca tM at
 * CatMat <= C at Mat
 * 三种组合方式
 *
 *
 * */
int wordBreak3(string &s, unordered_set<string> &dict){
    int size = s.size();
    vector<vector<int>> dp(size, vector<int>(size, 0));
    transform(s.begin(), s.end(), s.begin(), ::tolower);  // 全部变为小写字母
    unordered_set<string> hs;   // 构造一个新的集合，去重之后的数据
    for (auto str : dict){
        transform(str.begin(), str.end(), str.begin(), ::tolower); // 变为小写，存入字典
        hs.insert(str);
    }

    for (int i=0; i<size; i++){  // 记录[i,j)区间内的字符串是否在字典中，
        for (int j=i; j<size; j++){
            if (hs.count(s.substr(i, j-i+1)))  // 若在，标为１
                dp[i][j] = 1;
        }
    }
//    for (int i=0; i<size; i++){
//        for (int j=0; j<size; j++)
//            cout<<dp[i][j]<<" ";
//        cout<<endl;
//
//    }
//    cout<<endl;

    for (int i=0; i<size; i++){     // 记录以[i,j)区间内的字符串可以由字典中的几种组合构成
        for (int j=i; j<size; j++){
            for (int k=i; k<j; k++)  // 以i起始，k终止的字符串　和　以k+1起始，j终止的字符串有几种组合
                dp[i][j] += (dp[i][k] * dp[k+1][j]);
        }
    }

//    for (int i=0; i<size; i++){
//        for (int j=0; j<size; j++)
//            cout<<dp[i][j]<<" ";
//        cout<<endl;
//
//    }

    return dp[0][size-1];
}

void testTrans(){
    vector<int> first;
    vector<int> second;
    vector<int>::iterator it;

    // set some values:
    for (int i=1; i<6; i++)
        first.push_back (i*10);      //  first: 10 20 30 40 50

    second.resize(first.size());     // allocate space
    transform (first.begin(), first.end(), second.begin(), op_increase);
    // second: 11 21 31 41 51

    transform (first.begin(), first.end(), second.begin(), first.begin(), op_sum);
    //  first: 21 41 61 81 101

    cout << "first contains: ";
    for (it=first.begin(); it!=first.end(); ++it)
        cout << " " << *it;

    cout << endl;

    string s = "ABCDe";
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout<<s<<endl;
}

int main () {
    string s = "CatMat";
    string arr[] = {"Cat", "Mat", "Ca", "tM", "at", "C", "Dog", "og", "Do"};
    unordered_set<string> dict(arr, arr + sizeof(arr)/ sizeof(arr[0]));
    cout<<wordBreak3(s, dict)<<endl;
}
