/**
 * @author shaoDong
 * @email scut_sd@163.com
 * @create date 2018-09-16 03:36:04
 * @modify date 2018-09-16 03:36:04
 * @desc 能量石，前后可合并，能量综合为其长度的平方
*/

#include <iostream>
#include <vector>
using namespace std;

void makePowerVec(string p, vector<string> &powerVec)
{
    powerVec.push_back(p);
    for(int i = 0, j = p.size() - 1; i <= j; i++, j--)
    {
        if(p[i] == p[j])
        {
            string res = "";
            string temp = p.substr(0, j);
            res += temp;
            reverse(temp.begin(), temp.end());
            res += p[j];
            res += temp;
            powerVec.push_back(res);
        }
    }
}

bool havePower(string str, vector<string> &powerVec)
{
    for(int i = 0, len = powerVec.size(); i < len; i++)
    {
        if(str.find(powerVec[i]))
        {
            return true;
        }
    }
    return false;
}

bool cmp(pair<int, string> a, pair<int, string> b)
{
    return a.first < b.first;
}

int main(int argc, char const *argv[])
{
    string str, p;
    int lenStr, lenP, flag, tempLen, res = 0;
    vector<int> tempVec;
    vector<string> powerVec;
    vector< pair<int, string> > vecPair;
    // cin>>str>>p;
    str = "xyabababcba";
    p = "aba";
    // 构建能量石数组
    makePowerVec(p, powerVec);
    // 找出所有能量石的位置，以及能量石的名字
    lenStr = str.size();
    lenP = p.size();
    string strCopy = str;
    while(havePower(strCopy, powerVec))
    {
        for(int i = 0, len = powerVec.size(); i < len; i++)
        {
            int pos = strCopy.find(powerVec[i]);
            if(pos > -1)
            {
                vecPair.push_back(make_pair(pos, powerVec[i]));
                strCopy.erase(pos, powerVec[i].size());
            }
        }
    }
    sort(vecPair.begin(), vecPair.end(), cmp);
    for(int i = 0, len = vecPair.size(); i < len; i++)
    {
        cout<<vecPair[i].first<<","<<vecPair[i].second<<endl;
    }
    // 寻找连续的能量石
    // for(int i = 0, len = vecPair.size(); i < len; i++)
    // {
    //     int tempI = 0;
    //     tempLen = vecPair[i].second.size();
    //     for(int j = i; j < len; j++)
    //     {
    //         if(vecPair[j].first + vecPair[j].second.size() == vecPair[j + 1].first) 
    //         {
    //             tempI += vecPair[j + 1].second.size();
    //             tempLen += vecPair[j + 1].second.size();
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }
    //     tempVec.push_back(tempLen);
    //     i += tempI - 1;
    // }
    // // 求能量和
    // for(int i = 0, len = tempVec.size(); i < len; i++)
    // {
    //     res += tempVec[i] * tempVec[i];
    // }
    // cout<<res<<endl;
    return 0;
}
