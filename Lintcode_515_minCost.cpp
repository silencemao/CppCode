//
// Created by greg on 19-3-27.
//

#include <iostream>
#include <vector>
using namespace std;


/**
 * 房屋染色
 *
 * */
int minCost(vector<vector<int>> &costs) {
    // write your code here
    if (costs.size() < 1)
        return 0;

    vector<int> res(costs[0].begin(), costs[0].end());
    for (size_t i=1; i<costs.size(); i++){
        vector<int> tmp(3, 0);
        for (size_t j=0; j<costs[0].size(); j++){
            if (j==0)
                tmp[0] = min(res[1], res[2]) + costs[i][j];
            else if (j==1)
                tmp[1] = min(res[0], res[2]) + costs[i][j];
            else
                tmp[2] = min(res[0], res[1]) + costs[i][j];
        }
        res.clear();
        res.push_back(tmp[0]), res.push_back(tmp[1]), res.push_back(tmp[2]);
    }
    return min(min(res[0], res[1]), res[2]);
}

int main(){
    vector<vector<int>> costs;
    vector<int> tmp;

    tmp.push_back(14), tmp.push_back(2), tmp.push_back(11);
    costs.push_back(tmp);
    tmp.clear();

    tmp.push_back(11), tmp.push_back(14), tmp.push_back(5);
    costs.push_back(tmp);
    tmp.clear();

    tmp.push_back(14), tmp.push_back(3), tmp.push_back(10);
    costs.push_back(tmp);
    tmp.clear();

    cout<<minCost(costs)<<endl;

    return 0;
}