/**
 * @author shaoDong
 * @email scut_sd@163.com
 * @create date 2018-09-20 19:21:14
 * @modify date 2018-09-20 19:21:14
 * @desc 米兔从兔米那里了解到有一个无限长的数字序列: 1,  2，3，3，4，4，4,  5，5，5，5，5 ...,
 * (已知此数列有一定规律，现将这些数字按不同数值堆叠，相同值的数字在同一层)。
 * 米兔想知道这个数字序列的第n个数所在的那一层之前的层里共有多少个数
*/

#include <iostream>

using namespace std;

int fac(int n) 
{
    if(n < 2)
    {
        return 1;
    }
    return fac(n - 1) + fac(n - 2);
}

int main(int argc, char const *argv[])
{
    int n, sum = 0, i = 0, res = 0;
    cin>>n;
    while(sum < n)
    {
        sum += fac(i++);
    }
    for(int j = 0; j < i - 1; j++)
    {
        res += fac(j);
    }
    cout<<res<<endl;
    return 0;
}
