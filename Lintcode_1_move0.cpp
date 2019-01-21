//
// Created by greg on 17-9-23.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    void moveZeroes(vector<int>& nums) {
        // Write your code here
        int pos1 = 0;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[i] != 0)
            {
                if(i != pos1)  //pos1==i, do nothing and pos1++
                    nums[pos1] = nums[i];
                pos1++;
            }
        }

        for(int i=pos1; i<n; i++)
            nums[i] = 0;
    }
};

int main(){
    vector<int> a;
    for (int i=0; i<5; i++){
        a.push_back(i);
        a.push_back(0);

    }
    Solution s = Solution();
    for (int i=0;i<a.size();i++){
        cout<< a[i] <<" ";
    }
    cout << "" <<endl;
    s.moveZeroes(a);
    for (int i=0;i<a.size();i++){
        cout<< a[i] <<" ";
    }
}


