//
// Created by greg on 19-2-23.
//
#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    // write your code here
    size_t row = obstacleGrid.size();
    size_t col = obstacleGrid[0].size();
    if (obstacleGrid[0][0]==1)    // 如果第一个位置是１，则不能个再往后走，直接返回０
        return 0;

    vector<vector<int>> res(row, vector<int>(col, 0));
    for (size_t i=0; i<row; i++){
        for (size_t j=0; j<col; j++){
            if (obstacleGrid[i][j]==1)  // 如果为１，直接赋值为０
                res[i][j] = 0;

            else if (j==0){             // 此处一定是else if，如果是if的话，会覆盖上面判断生成的结果
                if (i==0)
                    res[i][j] = 1;
                else
                    res[i][j] = res[i-1][j];  // 当前位置是否走的通取决于上一个位置的值
            }
            else if (i==0){
                res[i][j] = res[i][j-1];
            }
            else
                res[i][j] = res[i-1][j] + res[i][j-1];
        }
    }

    return res[row-1][col-1];
}

int main(){
    vector<vector<int>> obstacleGrid;
    vector<int> tmp;
    tmp.push_back(1), tmp.push_back(0);
    obstacleGrid.push_back(tmp);
    tmp.clear();

    tmp.push_back(0), tmp.push_back(0);
    obstacleGrid.push_back(tmp);
    tmp.clear();

    tmp.push_back(0), tmp.push_back(0);
    obstacleGrid.push_back(tmp);
    tmp.clear();

    tmp.push_back(1), tmp.push_back(0);
    obstacleGrid.push_back(tmp);
    tmp.clear();

    tmp.push_back(0), tmp.push_back(0);
    obstacleGrid.push_back(tmp);
    tmp.clear();

    cout<<uniquePathsWithObstacles(obstacleGrid)<<endl;

    return 0;
}