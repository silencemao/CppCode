//
// Created by greg on 19-3-14.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 * 硬币排成线
 * 有 n 个硬币排成一条线。两个参赛者轮流从右边依次拿走 1 或 2 个硬币，
 * 直到没有硬币为止。拿到最后一枚硬币的人获胜。
 *
 * 第一个人拿１个第二个人拿２个，　第一个人拿２个第二个人拿一个，
 * 每次拿的总数都是三个，即如果最后剩１个或２个第一个人必胜，如果剩０个，第一个人必输
 *
 * */

bool firstWillWin(int n) {
    // write your code here
//    if (n==1 || n==2)
//        return true;
//    if (n==0 || n==3)
//        return false;
    return (n%3)!=0;
}



int main(){
    cout<<firstWillWin(10)<<endl;
    return 0;
}

