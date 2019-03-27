//
// Created by greg on 19-3-27.
//

#include <iostream>
using namespace std;


/**
 * 栅栏染色
 * 如果有１个柱子，有k种染色方案
 * 如果有２个柱子，前两个柱子有k*k种染色方案
 * 如果多于２个柱子，第３个柱子的颜色可以与第２个柱子颜色一致，那么第２个柱子的颜色必须和第１个不同，此时前３个柱子共有k*(k-1)种方案
 * 　　　　　　　　　第３个柱子的颜色与第２个柱子颜色不一致，那么和第一个柱子的颜色就无关了，此时前３个柱子共有k*k*(k-1)种方案
 *
 * 所以前三个柱子的染色方案共有k*(k-1) + k*k*(k-1)
 * 因此状态转移方程为 arr[i] = (arr[i-1] + arr[i-2]) * (k-1)
 * arr[i]记录了前i个柱子的染色方案
 *
 *　或者只用长度为２的数组即可，模仿斐波那切数列
 * */
int numWays(int n, int k){
    if (n<1)
        return 0;
    if (n==1)
        return k;
    if (n==2)
        return k*k;

    int arr[] = {k, k*k};

    for (int i=3; i<=n; i++){
        int tmp = (arr[0] + arr[1]) * (k-1);
        arr[0] = arr[1];
        arr[1] = tmp;
    }

    return arr[1];
}

int main(){
    return 0;
}