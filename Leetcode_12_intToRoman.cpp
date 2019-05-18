//
// Created by greg on 19-5-18.
//

#include <iostream>
using namespace std;


/**
 * https://leetcode.com/problems/integer-to-roman/
 * 数字转成罗马字符，
 * 首先生成一个数组，存储代表固定数字的罗马字符
 * 然后生成一个数组，存储罗马字符代表的数字
 * 然后开始遍历罗马字符数组，只要数字大于当前字符对应的数字，就把这个字符加入到结果中。
 * */
string intToRoman(int num){
    string symbol[] = {"M", "CM",  "D", "CD",  "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int arr[]       = {1000, 900,  500,  400,  100,  90,  50,  40,  10,    9,   5,    4,   1};
    string result = "";

    for (int i=0; i< sizeof(symbol)/ sizeof(symbol[0]); i++){
        while (num >= arr[i]){
            num -= arr[i];
            result += symbol[i];
        }
    }

    return result;
}

int main(){
    int num = 801;
    cout<<intToRoman(num)<<endl;

    return 0;
}