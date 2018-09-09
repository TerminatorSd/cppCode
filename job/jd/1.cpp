/**
 * @author shaoDong
 * @email scut_sd@163.com
 * @create date 2018-09-09 07:45:01
 * @modify date 2018-09-09 07:45:01
 * @desc 
    数学课上，老师揪出了老是和旁边同学交头接耳的小Q，为此老师提出了一个问题看小Q是否对知识有所掌握。
    老师给了小Q n个整数，要求小Q往其中加入一个数，但数列的中位数保持不变。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, temp;
    float nowMid, res;
    vector<int> inputVec;
    // input
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>temp;
        inputVec.push_back(temp);
    }
    // sort
    sort(inputVec.begin(), inputVec.end());
    // get now middle
    if(n % 2)
    {
        nowMid = inputVec[n / 2];
    }
    else
    {
        nowMid = (float)(inputVec[n / 2 - 1] + inputVec[n / 2]) / 2;
    }
    cout<<nowMid<<endl;
    return 0;
}
