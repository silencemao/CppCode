//
// Created by greg on 17-9-24.
//输入：排序后的数组。输出：每个元素保留两个。
//

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums){
    int i = 0;
    for (int n : nums){
        if (i<2 || nums[i-2]<n){
            nums[i++] = n;
            cout<<i<<" ";
        }
    }
    return i;
}

int main(){
    vector<int> nums;
    for (int i=0; i<5; i++){
        nums.push_back(i);
        nums.push_back(i);
        nums.push_back(i);
    }

    for (int n : nums){
        cout<<n<<" ";
    }
    cout<<endl;
    int a = removeDuplicates(nums);
    cout<<endl;
    for (int i=0; i<a;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    cout<<a<<endl;

}