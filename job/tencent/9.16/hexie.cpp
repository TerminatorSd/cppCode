/**
 * @author shaoDong
 * @email scut_sd@163.com
 * @create date 2018-09-16 03:07:37
 * @modify date 2018-09-16 03:07:37
 * @desc 和谐的数字
*/

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, temp, nowSum = 0;
    vector<int> vectorInput;
    // input
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>temp;
        vectorInput.push_back(temp);
    }
    for(int j = 0; j < n; j++)
    {
        temp = vectorInput[j];
        while(temp / 10)
        {
            nowSum += temp % 10;
            temp /= 10;
        }
        nowSum += temp;
        if(vectorInput[j] % nowSum == 0)
        {
            cout<<"Yes"<<endl;
        }
        else 
        {
            cout<<"No"<<endl;
        }
        nowSum = 0;
    }
    return 0;
}

