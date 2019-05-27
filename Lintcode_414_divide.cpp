//
// Created by greg on 19-5-27.
//

#include <iostream>
using namespace std;

/**
 * https://www.lintcode.com/problem/divide-two-integers/description
 * 两数相除，不用乘法、除法
 * 如果溢出(超出32位有符号整型表示范围)，返回 2147483647
 * 除法就是减法的集合，现在不让用除法直接来实现两数相除，就用减法来代替
 * 最简单的方法就是看a能减去b多少会，就是除法的结果。
 * 现在可以使用移位操作来加速这个做法，
 * */
int divide(int dividend, int divisor){
    if (dividend==0)
        return 0;
    if (divisor==0)
        return INT32_MAX;

    int flag = (dividend > 0)==(divisor > 0) ? 1 : -1;  // 判断正负
    long long a = llabs(dividend), b = llabs(divisor), result = 0;
    while (a >= b){
        for (long long c=b, cnt=1; a>=c; c<<=1, cnt<<=1){  //　c cnt逐渐倍增
            a -= c;
            result += cnt;
        }
    }
    if (result==2147483648 && flag>0)
        return 2147483647;
    return flag * result;
}

int main(){
    cout<<divide(0, 1)<<endl;
    return 0;
}