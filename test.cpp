/**
 * @author shaoDong
 * @email scut_sd@163.com
 * @create date 2018-10-09 18:54:05
 * @modify date 2018-10-09 18:54:05
 * @desc 美团点评2018 校招第二批笔试
 * 某个城市的车牌号由n位数字组成，已知有一位富豪对车牌号有着狂热的追求，他希望自己的车牌号里面至少有k个相同的数字。
 * 他已经申请了一个车牌号，如果他要将车牌号中的一个数字b替换成a，则需要花费|a-b|元，问富豪需要至少花费多少钱才能让车牌号符合他的要求。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    int n = 8, k = 7, res, min = 9999, resIndex;
    string target = "94476413";
    vector<int> tempVec, smallVec;
    vector< vector<int> > outVec;
    // input
    // cin>>n>>k>>target;
    // 对于输出字符串的每一位，求出将其他所有位数转变为当前值的代价
    for(int i = 0; i < n; i++) {
        int tempInt = target[i] - '0';
        int sum = 0;
        for(int j = 0; j < n; j++) {
            if(j != i) {
                int tempRes = abs(tempInt - (target[j] - '0'));
                tempVec.push_back(tempRes);
            }
        }
        sort(tempVec.begin(), tempVec.end());
        for(int l = 0; l < k - 1; l++) {
            sum += tempVec[l];
        }
        // 代价、目标值和最大差
        smallVec.push_back(sum);
        smallVec.push_back(tempInt);
        smallVec.push_back(tempVec[k - 2]);
        outVec.push_back(smallVec);
        tempVec.clear();
        smallVec.clear();
    }
    for(int m = 0; m < n; m++) {
        // cout<<outVec[m][0]<<" ";
        if(outVec[m][0] < min) {
            min = outVec[m][0];
            resIndex = m;
        }
    }
    for(int p = 0; p < n; p++) {
        if(abs(target[p] - '0' - outVec[resIndex][1]) <= outVec[resIndex][2]) {
            target[p] = outVec[resIndex][1] + '0';
        }
    }
    cout<<outVec[resIndex][0]<<endl;
    cout<<target<<endl;
    return 0;
}
