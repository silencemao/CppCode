//
// Created by greg on 19-5-13.
//

#include <iostream>
#include <tgmath.h>

using namespace std;

/**
 * https://www.lintcode.com/problem/reverse-integer/description
 *
 * 将一个整数中的数字进行颠倒，当颠倒后的数出现溢出时，返回０
 * */
int reverseInteger(int n){
    bool flag = false;
    if (n < 0)
        flag = true;  // 为负数

    n = abs(n);   // 这样做可能会出错，当n=-2147483648时，取逆就会变为0
    int res = 0;
    while (n != 0){
        if (res > INT32_MAX/10)
            return 0;
        res  = res * 10 + n%10;
        n = n / 10;
    }

    if (flag){
        res = -res;
        if (res < INT32_MIN)
            res = 0;
    }

    return res;
}

int reverseInteger1(int n){
    int res = 0;
    while (n != 0){
        if (res > INT32_MAX/10 || res < INT32_MIN/10)
            return 0;

        res = res * 10 + n%10;
        n = n / 10;
    }
    return res;
}

int main(){

    int n = -1230;
    int m = 2147483647;

    cout<<pow(2, 31)<<endl;
    cout<<reverseInteger(n)<<endl;
    return 0;
}