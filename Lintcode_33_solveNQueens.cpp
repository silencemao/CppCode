//
// Created by greg on 18-11-15.
//
#include <iostream>
#include <vector>

using namespace std;

/**
 * N皇后
 * */

int sum = 0;
int flag[9];

bool conflict(int numLevel){
    for (int i=1; i<numLevel; i++){
        if ((flag[i]==flag[numLevel]) || (abs(i-numLevel)) == abs(flag[i] - flag[numLevel]))
            return true;
    }
    return false;
}


void eightQuenne(int numLevel, int n){
    int N = n;
    vector<vector<string>> res(N, vector<string>(N, "."));
    if (numLevel > N){
        for (int i=1; i<=N; i++){
            res[i-1][flag[i]-1] = "Q";
            cout<<flag[i]<<" ";
        }
        cout<<endl;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++)
                cout<<res[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        sum++;
    }
    else {
        for (int i=1; i<=N; i++){
            flag[numLevel] = i;
            if (!conflict(numLevel))
                eightQuenne(numLevel+1, n);
        }
    }
}


int main(){
    int n = 0;
    cin>>n;
    eightQuenne(1, n);
    cout<<sum<<endl;
    return 0;
}
