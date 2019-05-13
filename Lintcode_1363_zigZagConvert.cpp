//
// Created by greg on 19-5-13.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 * 之字形遍历字符串
 *　https://www.lintcode.com/problem/zigzag-conversion/description
 * Input: "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * Explanation:
   After conversion, we get
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
  Read line by line, the answer is "PAHNAPLSIIGYIR".
 *
 * 最终的结果是把新的遍历方式得到的字符串按照行拼接起来，然后把拼接后的字符串返回
 *
 * 我们需要生成numRows个小的字符串tmp(numRows)，然后按照之字形的遍历方式，把每一个字符依次存入tmp[i]中
 * 当存入到第numRows-1个字符串后，我们需要把下一个字符存入到第numRows-2个字符串中，所以引入step来控制row
 * 的数值。
 * */
string convert(string &s, int numRows){
    if (numRows <= 1 || s.size() < numRows)
        return s;

    vector<string> tmp(numRows);
    int row = 0, step = 1;
    for (int i=0; i<s.size(); i++){
        if (row==numRows-1)
            step = -1;
        if (row==0)
            step = 1;

        tmp[row] += s[i];
        row += step;
    }

    string res = "";
    for (int i=0; i<numRows; i++)
        res += tmp[i];
    return res;
}

int main(){

    string s = "PAYPALISHIRING";
    int r = 3;
    cout<<convert(s, r)<<endl;
    return 0;
}