/**
 * @author shaoDong
 * @email scut_sd@163.com
 * @create date 2018-09-20 19:40:04
 * @modify date 2018-09-20 19:40:04
 * @desc n 个非负整数的柱状图，能接多少水
 * 输入：[0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
*/

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int res = 0;
    char temp;
    string str;
    // vector<int> inputVec(arr, arr + 12);
    vector<int> inputVec;
    // input
    while(true)
    {
        temp = getchar();
        if(temp == '\n')
        {
            break;
        }
        else
        {
            int num = int(temp) - 48;
            if(num >= 0 && num <= 9)
            {
                inputVec.push_back(num);
            }
        }
    }
    cout<<inputVec.size();
    // cin>>str;
    // for(int i = 0, len = str.size(); i < len; i += 2)
    // {
    //     inputVec.push_back(int(str[i]) - 48);
    // }
    // cout<<int(str[0])<<endl;

    for(int i = 0, len = inputVec.size() - 1; i < len; i++)
    {
        // cout<<inputVec[i]<<" ";
        for(int j = i + 1; j < len; j++)
        {
            // 从每个位置向后找到第一个大于等于自己高度的位置，然后计算中间的面积
            if(arr[i] <= arr[j])
            {
                if(j - i > 1)
                {
                    int min = arr[i] > arr[j] ? arr[j] : arr[i];
                    for(; i < j; i++)
                    {
                        res += min - arr[i];
                    }
                    i--;
                }
                break;
            }
            else
            {
                continue;
            }
        }
    }
    // cout<<endl;
    cout<<res<<endl;
    return 0;
}
