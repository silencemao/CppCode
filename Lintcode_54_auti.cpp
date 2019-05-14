//
// Created by greg on 19-5-14.
//

#include <iostream>
using namespace std;

int atoi(string &str){
    int i=0;
    for (; isspace(str[i]); i++);

    bool flag = false;
    if (str[i]=='-' || str[i]=='+'){
        flag = (str[i]=='-');
        i++;
    }
    int res = 0;
    for (;isdigit(str[i]); i++){
        int tmp = str[i] - '0';
        if (flag){
            if (-res < (INT32_MIN + tmp)/10)
                return INT32_MIN;
        }
        else{
            if (res > (INT32_MAX - tmp) / 10)
                return INT32_MAX;
        }

        res = res * 10 + tmp;
    }

    return flag ? -res : res;

}


int main(){

    string a = "  -2147483648 ";
    cout<<atoi(a)<<endl;

    return 0;
}
