/**
 * @author shaoDong
 * @email scut_sd@163.com
 * @create date 2018-09-16 03:17:50
 * @modify date 2018-09-16 03:17:50
 * @desc 巧克力条上有n 个巧克力球，巧克力球上有坚果或者没有，掰开巧克力条，保证每一块都有一个坚果，有多少种方法
*/

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int n, temp, res = 1, zeroNum = 0, flag = 0;
    vector<int> vectorInput, tempVec;
    // input
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>temp;
        vectorInput.push_back(temp);
    }
    for(int j = 0; j < n; j++) 
    {
        if(vectorInput[j] == 1) 
        {
            if(vectorInput[j - 1] == 0)
            {
                tempVec.push_back(zeroNum);
                zeroNum = 0;
            }
            flag = 1;
        }
        else 
        {
            if(flag)
            {
                zeroNum++;
            }
        }
    }
    for(int k = 0, len = tempVec.size(); k < len; k++)
    {
        res *= tempVec[k] + 1;
    }
    cout<<res<<endl;
    return 0;
}
