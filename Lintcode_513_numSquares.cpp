//
// Created by greg on 19-3-25.
//
#include <iostream>
#include <vector>
#include <tgmath.h>

using namespace std;
// 完美平方

/**
 * dfs全部找出来，会超时
 * */
void dfs(vector<vector<int>> &res, vector<int> &cur, vector<int> arr, int index, int target){
    if (target==0 || index>=arr.size()){
        if (target==0){
            if (res.empty())
                res.push_back(cur);
            else if (res[0].size() >= cur.size()){
                res.pop_back();
                res.push_back(cur);
            }
        }
        return;
    }

    for (int i=index; i<arr.size(); i++) {
        if (target >= arr[i]) {
            cur.push_back(arr[i]);
            dfs(res, cur, arr, i, target - arr[i]);
            cur.pop_back();
        }
    }
}

int numSquares(int n){
    int sqrtNum = int(sqrt(n));
    vector<int> arr;
    for (int i=1; i<=sqrtNum; i++)
        arr.push_back(i*i);

    vector<vector<int>> res;
    vector<int> cur;
    dfs(res, cur, arr, 0, n);

    return res[0].size();

}

/**
 * p(n) = p(n-1) + 1
 * p(n) = p(n-4) + 1
 * p(n) = p(n-9) + 1
 * ....
 * 也就是说先计算出前面数字的最短
 *
 * */
int numSquares1(int n){
    vector<int> nums(n+1, 0);
    for (int i=1; i<=n; i++)
        nums[i] = i;

    for (int i=1; i<n+1; i++){
        for (int tmp=1; tmp*tmp<=i; tmp++)
            nums[i] = min(nums[i], nums[i-tmp*tmp]+1);
    }

    return nums[n];
}

int main(){
    cout<<numSquares1(12)<<endl;

    return 0;
}
