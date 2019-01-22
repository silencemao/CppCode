//
// Created by greg on 17-9-25.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int median(vector<int> &nums){
    sort(nums.begin(), nums.end());
    int length = nums.size();
    if (length % 2 == 1){
        return nums[length/2];
    }

    else{
        return nums[length/2-1];
    }

}

int main(){
    vector<int> a;
    a.push_back(7);
    a.push_back(3);
    a.push_back(9);
    a.push_back(1);
    a.push_back(4);
    cout<<median(a)<<endl;

    return 0;
}


