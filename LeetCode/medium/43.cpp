/**
 * @author shaoDong
 * @email scut_sd@163.com
 * @create date 2018-09-16 10:13:04
 * @modify date 2018-09-16 10:13:04
 * @desc 字符串相乘
*/

#include <iostream>
using namespace std;

string multiply(string num1, string num2) {
    if(num1 == "0" || num2 == "0")
    {
        return "0";
    }
    string res;
    int carry, temp = 0;
    int len1 = num1.size(), len2 = num2.size();
    // 反转两个字符串
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    for(int i = 0; i < len1 + len2 - 1; i++)
    {
        // 错位相乘，并将和相加
        for(int j = 0; j <= i; j++)
        {
            int a = (j < len1 ? num1[j] - '0' : 0);
            int b = (i - j < len2 ? num2[i - j] - '0' : 0);
            temp = temp + a * b;
        }
        res = char(temp % 10 + '0') + res;
        temp /= 10;
    }
    if(temp != 0)
    {
        res = char(temp + '0') + res;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    string a = "12";
    string b = "12";
    string res = multiply(a, b);
    cout<<res<<endl;
    return 0;
}

