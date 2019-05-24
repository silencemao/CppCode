//
// Created by greg on 18-1-10.
//
#include <iostream>
#include <vector>
using namespace std;
/**
 * 电话号码0-9分别对应一下的几个字符串,给定一个数字组合, 返回他们所有的字母组合
 * 输入 : 23
 * 输出 : ad ae af bd be bf cd ce cf
 * */
class Solutions{
private:
    string mapping[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void dfs(vector<string> &res, string &cur, string &digits, int index){
        if (index==digits.length()){
            res.push_back(cur);
            return;
        }
        string letter = mapping[digits[index] - '0'];
        for (int i=0; i<letter.length(); i++){
            cur.push_back(letter[i]);
            dfs(res, cur, digits, index+1);
            cur.pop_back();
        }
    }


    void dfs1(vector<string> &res, string &cur, string &digits, int index){
        if (index==digits.length()){
            res.push_back(cur);
            return;
        }
        string letter = mapping[digits[index]-'0'];
        for (int i=index; i<letter.length(); i++){
            cur.push_back(letter[i]);
            dfs(res, cur, digits, i+1);
            cur.pop_back();
        }
    }
public:
    vector<string> letterCombinations2(string &digits){
        if (digits.length()==0) return {};
        vector<string> res = {""};
        for (char digit : digits){
            vector<string> tmp;
            for (string &s : res){
                for (char c : mapping[digit-'0'])
                    tmp.push_back(s+c);
            }
            res.swap(tmp);
        }
        return res;
    }

    vector<string> letterCombinations3(string &digits){
        vector<string> res = {""};

        for (char num : digits){
            vector<string> tmp;
            for (string &str : res){
                for (char s : mapping[num-'0']){
                    tmp.push_back(str+s);
                }
            }
            res.swap(tmp);
        }
        return res;
    }

    vector<string> letterCombinations(string &digits){
        if (digits.length()==0)
            return {};
        vector<string> res;
        string cur;
        dfs(res, cur, digits, 0);
        return res;

    }
};


vector<string> letterCombinations(string &digits){
    vector<string> result = {""};
    if (digits.size()==0)
        return {};
    string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    for (char digit : digits){  // 遍历每一个数字
        vector<string> tmp;
        for (string str : result){  // 遍历result中的每一个字符串
            string letter = mapping[digit-'0'];
            for (char c : letter)   // 遍历每一个字母
                tmp.push_back(str+c);
        }
        result.swap(tmp);
    }
    return result;
}

int main(){
    string digits = "";
    Solutions *s = new Solutions();
    while (cin>>digits){
        vector<string> res = letterCombinations(digits);
        for (auto str : res){
            cout<<str<<" ";
        }
        cout<<endl;
    }
}




