//
// Created by greg on 19-4-19.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 * 目标和，给定一个数组[1, 1, 1, ,1 ,1]一个目标target
 * 在数字之家加上'+' '-'号，计算有几种方式可以得到目标target值
 * */
void dfs(int &answer, int *res, int tmp, vector<int> nums, int index, int target){
    if (index==nums.size()){
        if (tmp==target)
            answer++;
    }

    else if (abs(tmp-target) <= res[index]){
        dfs(answer, res, tmp+nums[index], nums, index+1, target);
        dfs(answer, res, tmp-nums[index], nums, index+1, target);
    }
}

int findtargetSumWays(vector<int> &nums, int s){
    int res[31] = {0};
    int answer = 0;
    int tmp = 0;
    res[nums.size()-1] = nums.back();
    if (nums.size()>0){
        for (int i=nums.size()-2; i>=0; i--)
            res[i] = res[i+1] + nums[i];

        dfs(answer, res, tmp, nums, 0, s);
    }

    return answer;
}

void dfs1(int &answer, vector<int> nums, int s, int index){
    if (index==nums.size()){
        if (s==0)
            answer++;
        return;
    }
//    if (s!=0){
        dfs1(answer, nums, s+nums[index], index+1);
        dfs1(answer, nums, s-nums[index], index+1);
//    }

}

int findtargetSumWays1(vector<int> &nums, int s){
    int answer = 0;
    dfs1(answer, nums, s, 0);
    return answer;
}

int main(){
    int arr[] = {1, 1, 1, 1, 1};
    vector<int> nums(arr, arr+ sizeof(arr)/ sizeof(arr[0]));
    int s = 3;
    cout<<findtargetSumWays1(nums, s);

    return 0;
}