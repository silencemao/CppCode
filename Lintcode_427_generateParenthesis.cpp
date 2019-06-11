//
// Created by greg on 19-6-11.
//

#include <iostream>
#include <vector>

using namespace std;


/**
 * 给定数字n，生成配对的括号
 * 如果右括号数量等于数字n，那么满足条件，直接加入到result中
 * 如果左括号数据等于n，加上剩余的右括号即可满足条件
 * 如果左右括号不相等：
 *    如果左括号数量多于右括号，直接加入右括号，进入下一层
 *    如果左括号少于或者等于右括号数量，加入左括号，进入下一层
 * */
void helper(string s, vector<string> &result, int l, int r, int n){
    if (r==n)
        result.push_back(s);
    else if (l == n){
        s += string(n-r, ')');
        result.push_back(s);
    }
    else {
        if (l > r)
            helper(s+')', result, l, r+1, n);
        helper(s+'(', result, l+1, r, n);
    }
}

vector<string> generateParenthesis(int n){
    string s = "";
    vector<string> result;
    helper(s, result, 0, 0, n);
    return result;
}

int main(){
    int n = 3;
    vector<string> result = generateParenthesis(n);
    cout<<"[";
    size_t size = result.size();
    for (size_t i=0; i<size-1; i++){
            cout<<"\""<<result[i]<<"\""<<", ";
//        cout<<endl;
    }
    cout<<"\""<<result[size-1]<<"\"";
    cout<<"]"<<endl;
    return 0;
}