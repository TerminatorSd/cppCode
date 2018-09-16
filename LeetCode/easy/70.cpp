/**
 * @author shaoDong
 * @email scut_sd@163.com
 * @create date 2018-09-16 09:41:40
 * @modify date 2018-09-16 09:41:40
 * @desc 爬楼梯，一步或两步
*/
#include <iostream>
using namespace std;

// 递归法，n 需要小于一定值，否则时间爆炸
// int climbStairs(int n) {
//     if(n == 1) 
//     {
//         return 1;
//     }
//     else if(n == 2) 
//     {
//         return 2;
//     }
//     return (climbStairs(n - 1) + climbStairs(n - 2));
// }

// 斐波那契数列法
int climbStairs(int n) {
    int dp[1000];
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main(int argc, char const *argv[])
{
    int n, res;
    cin>>n;
    res = climbStairs(n);
    cout<<res<<endl;
    return 0;
}


