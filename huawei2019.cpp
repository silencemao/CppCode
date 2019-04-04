//
// Created by greg on 19-4-4.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 * 给定多个数组和一个数字length，
 * 每次取每一个数组length个数字，合并到新的数组内
 *
 * 1 2 3 4 5 6 7
 * 8 9 10 11 12 13
 * 14 15 16 17 18 19
 * length = 3
 * 1,2,3,8,9,10,14,15,16,4,5,6,11,12,13,17,18,19,7,
 *
 * */
vector<int> mergeArr(vector<vector<int>> &nums, int length){
    vector<int> res;
    if (length < 1)
        return {};
    vector<int> index(nums.size(), 0);

    int size = 0;
    for (int i=0; i<nums.size(); i++){
        if (nums[i].size() > size)
            size = nums[i].size();
    }

    int loopNum = 0;
    if (size % length==0)
        loopNum = size / length;
    else if (size % length < size)
        loopNum = size / length + 1;
    else
        loopNum = 1;

    for (int tmp=0; tmp < loopNum; tmp++){
        for (int i=0; i<nums.size(); i++){
            if (index[i] >= 0 && index[i] < nums[i].size()){
                int start = index[i], end = min(start+length, int(nums[i].size()));
                for (int j = start; j < end; j++)
                    res.push_back(nums[i][j]);
                if (end < nums[i].size())
                    index[i] = end;
                else
                    index[i] = -1;
            }
        }

    }
    return res;
}

int main(){
    vector<vector<int>> arr;
    vector<int> tmp;
    tmp.push_back(1), tmp.push_back(2), tmp.push_back(3), tmp.push_back(4), tmp.push_back(5), tmp.push_back(6), tmp.push_back(7);
    arr.push_back(tmp);
    tmp.clear();

    tmp.push_back(8), tmp.push_back(9), tmp.push_back(10), tmp.push_back(11), tmp.push_back(12), tmp.push_back(13);
    arr.push_back(tmp);
    tmp.clear();

    tmp.push_back(14), tmp.push_back(15), tmp.push_back(16), tmp.push_back(17), tmp.push_back(18), tmp.push_back(19);
    arr.push_back(tmp);

    for (auto vec : arr){
        for (auto num : vec)
            cout<<num<<" ";
        cout<<endl;
    }


    vector<int> res = mergeArr(arr, 3);
    for (auto num : res)
        cout<<num<<",";
    cout<<endl;


    return 0;
}