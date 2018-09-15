/**
 * @author shaoDong
 * @email scut_sd@163.com
 * @create date 2018-09-14 07:52:23
 * @modify date 2018-09-14 07:52:23
 * @desc [description]
*/

#include <iostream>

using namespace std;

int main()
{
    long int x, y, res = 0;
    cin>>x>>y;
    if(y / x < 2)
    {
        res = (x >= y ? y - 1 : x) - (y / 2);
    }
    cout<<res<<endl;
    return 0;
}
