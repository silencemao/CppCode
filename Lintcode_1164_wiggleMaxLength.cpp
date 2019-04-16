//
// Created by greg on 19-4-16.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 * 摆动序列，数字之间的差是正负交替出现的，则视数组为摆动序列
 * 可以对数组中的数字进行删减，获得最大长度的摆动序列
 *
 * */
int wiggleMaxLength(vector<int> &nums) {
    // Write your code here
    size_t size = nums.size();
    if (size==0)
        return 0;
    if (size==1)
        return 1;
    if (size==2 && nums[0]!=nums[1])
        return 2;

    vector<int> up(size, 0);   // 上升序列，记录上升数字的长度
    vector<int> down(size, 0); // 下降序列
    up[0] = down[0] = 1;
    for (int i=1; i<size; i++){
        if (nums[i] > nums[i-1]){  // nums[i] > nums[i-1] 上升，应该在down[i-1]的基础上加１，因为up[i-1]记录的是上升的长度
            up[i] = down[i-1] + 1;
            down[i] = down[i-1];
        }
        else if (nums[i] < nums[i-1]){
            down[i] = up[i-1] + 1;
            up[i] = up[i-1];
        }
        else{
            up[i] = up[i-1];
            down[i] = down[i-1];
        }
    }
    return max(up.back(), down.back());

}

int main(){
    int arr[] = {3, 3, 3, 2, 5};
    vector<int> nums(arr, arr+ sizeof(arr)/ sizeof(arr[0]));
    cout<<wiggleMaxLength(nums)<<endl;
    return 0;

}