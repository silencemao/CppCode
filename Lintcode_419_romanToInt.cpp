//
// Created by greg on 19-5-19.
//

#include <iostream>
using namespace std;

/**
 * 罗马字符转为int数字
 * */

int romanToInt(string &s){
    if (s.size() < 1)
        return 0;

    string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int arr[]       = {1000, 900, 500, 400,  100,  90,   50,  40,   10,  9,    5,    4,   1};

    size_t size = s.size();
    int start = 0;
    int result = 0;
    while (start < size){
        for (int i=0; i< sizeof(symbol)/ sizeof(symbol[0]) && start < size; i++){
            if (symbol[i]==s.substr(start, 2)){  // 优先对比起始为start的两个字符对应的数字，如CM　CD等
                result += arr[i];
                start += 2;
            }
            else if (symbol[i]==s.substr(start, 1)){
                result += arr[i];
                start += 1;
            }
        }
    }
    return result;
}

/**
 * 方法二
 * */
int romanCharToInt(char ch){
    int d = 0;
    switch (ch){
        case 'I':
            d = 1;
            break;
        case 'V':
            d = 5;
            break;
        case 'X':
            d = 10;
            break;
        case 'L':
            d = 50;
            break;
        case 'C':
            d = 100;
            break;
        case 'D':
            d = 500;
            break;
        case 'M':
            d = 1000;
            break;
    }
    return d;
}

int romanToInt2(string &s){
    if (s.size() < 1)
        return 0;

    int result = romanCharToInt(s[0]);
    for (int i=1; i<s.size(); i++){
        int prev = romanCharToInt(s[i-1]);
        int curr = romanCharToInt(s[i]);
        if (prev < curr)
            result  = result - prev + (curr - prev);
        else
            result += curr;
    }

    return result;
}

int main(){
    string str = "LVIII";
    cout<<romanToInt2(str)<<endl;
    return 0;
}