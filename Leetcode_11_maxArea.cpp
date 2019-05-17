//
// Created by greg on 19-5-17.
//

#include <iostream>
#include <vector>
using namespace std;


/**
 * https://leetcode.com/problems/container-with-most-water/
 * 最大容器，给定一个数组height，里面的每一个数字和对应的下表组成一个点[i, height[i]]
 * (i, 0) - (i, height[i])组成一条线。
 * 找出两条线，包围的面积最大。
 *
 * */
int maxArea(vector<int> &height){
    if (height.size() < 2)
        return 0;

    int left = 0, right = height.size() - 1;
    int area = 0;
    while (left < right){
        int tmp = (right - left) * (height[left] < height[right] ? height[left++] : height[right--]);

        area = area < tmp ? tmp : area;
    }
    return area;
}

int main(){
    int arr[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> height(arr, arr + sizeof(arr)/ sizeof(arr[0]));
    cout<<maxArea(height)<<endl;

    return 0;
}