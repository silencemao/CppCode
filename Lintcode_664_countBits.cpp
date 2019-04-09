//
// Created by greg on 19-4-9.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int num){
    vector<int> f(num+1, 0);
    for (int i=1; i<=num; i++){
        cout<<i-1<<" "<<i<<" "<<(i&(i-1))<<endl;
        f[i] = f[i&(i-1)] + 1;
    }
    return f;
}

int main(){
    int num = 5;
    vector<int> res = countBits(num);
    for (auto n : res)
        cout<<n<<" ";
    cout<<endl;

    return 0;
}