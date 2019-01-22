//
// Created by greg on 17-9-24.
//
#include <iostream>
#include <vector>

using namespace std;
vector<int> twoSum(vector<int> &numbers, int target){
    vector<int> a;
    for (int i=0; i<numbers.size(); i++){
        for (int j=i+1; j<numbers.size(); j++){
            if (target==(numbers[i]+numbers[j])){
                a.push_back(i+1);
                a.push_back(j+1);
                return a;
            }
        }
    }
}


int main(){
    vector<int> a;
    a.push_back(1);
    a.push_back(0);
    a.push_back(-1);
    vector<int> result = twoSum(a, -1);
    for (int n : result){
        cout<<n<<" ";
    }
}