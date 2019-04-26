//
//https://leetcode.com/problems/squares-of-a-sorted-array/submissions/
// Created by greg on 19-4-26.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 * 给定一个非递减数组，对数组中的所有元素进行平方，返回一个非递减的数组
 *
 * 二分法找到这个数组中绝对值最接近0的位置，
 * 如果数组全为正数，则low指向第一个数
 * 如果数组全为负数，则high指向最后一个数
 * 如果有正有负，low指向最后一个负数
 * */
vector<int> sortedSquares(vector<int> &A){
    vector<int> res;
    int low = 0, high = A.size()-1, mid = 0;
    while (low <= high){
        mid = (low+high)>>1;
        if (A[mid] >= 0)
            high = mid - 1;
        if (A[mid] < 0)
            low = mid + 1;
    }
    if (A[mid] > 0 && mid > 0)  // 保证A[mid]==0 or mid=0
        mid--;

    low = mid, high = mid+1;
    while (low >=0 && high<A.size()){
        if (abs(A[low]) >= abs(A[high])){
            res.push_back(A[high] * A[high]);
            high++;
        }

        else if (abs(A[low]) < abs(A[high])){
            res.push_back(A[low] * A[low]);
            low--;
        }
    }

    for (; low>=0; low--)
        res.push_back(A[low] * A[low]);
    for (; high<A.size(); high++)
        res.push_back(A[high] * A[high]);
    return res;
}

int main(){
    int arr[] = {-7, -4, -4, -2, 11};
    vector<int> A(arr, arr + sizeof(arr)/ sizeof(arr[0]));
    vector<int> res = sortedSquares(A);
    for (auto num : res)
        cout<<num<<" ";
    cout<<endl;
    return 0;
}