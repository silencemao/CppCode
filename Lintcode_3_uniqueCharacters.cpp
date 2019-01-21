//
// Created by greg on 17-9-24.
//
#include <iostream>
using namespace std;

bool isUnique(string &str){
    for (int i=0; i<str.size(); i++){
        for (int j=i+1; j<str.size(); j++){
            if (str[i] == str[j]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    string str = "abcdedsa";
    bool a = isUnique(str);
    cout<<a;
    return 0;
}