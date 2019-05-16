//
// Created by greg on 19-5-16.
//
#include <iostream>
#include <algorithm>

using namespace std;

/**
 *
 * https://www.lintcode.com/problem/palindrome-number/description
 * 判断数字是否为回文数字，
 * -123　不是
 *  121  是
 *  11   是
 * */
int reverse(int num){
    int y = 0;
    while (num != 0){
        int tmp = num % 10;
        if (y > (INT32_MAX -tmp) / 10)
            return false;

        y = y * 10 + tmp;
        num /= 10;
    }
    return y;
}

bool isPalindrome(int num){
    if (num < 0)
        return false;

    string num2str = to_string(num);
    reverse(num2str.begin(), num2str.end());

    cout<<num2str<<endl;
    return num2str==to_string(num);
}

int main(){
    int num = -121;
    cout<<isPalindrome(num)<<endl;

    return 0;
}
