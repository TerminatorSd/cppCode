/**
 * @author shaoDong
 * @email scut_sd@163.com
 * @create date 2018-09-16 03:36:04
 * @modify date 2018-09-16 03:36:04
 * @desc 能量石，前后可合并，能量综合为其长度的平方
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

void makePowerVec(string p, vector<string> powerVec)
{
    powerVec.push_back(p);
    for(int i = 0, j = p.size() - 1; i <= j; i++, j--)
    {
        if(p[i] == p[j])
        {

        }
    }
}

int main(int argc, char const *argv[])
{
    string str, p;
    int lenStr, lenP, flag, tempLen, res = 0;
    vector<int> tempVec;
    vector<string> powerVec;
    vector< pair<int, string> > vecPair;
    cin>>str>>p;
    // 构建能量石数组
    makePowerVec(p, powerVec);
    // 寻找能量石
    lenStr = str.size();
    lenP = p.size();
    for(int i = 0; i < lenStr; i++)
    {
        if(str[i] == p[0])
        {
            flag = 1;
            for(int j = 1; j < lenP; j++)
            {
                if(str[i + j] == p[j])
                {
                    continue;
                }
                else 
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
            {
                vecPair.push_back(make_pair(i, p));
                i += lenP - 1;
            }
        }
    }
    for(int i = 0, mapLen = vecPair.size(); i < mapLen; i++)
    {
        tempLen = vecPair[i].second.size();
        for(int j = i; j < mapLen; j++)
        {
            if(vecPair[j].first + vecPair[j].second.size() == vecPair[j + 1].first) 
            {
                tempLen += vecPair[j + 1].second.size();
            }
            else
            {
                break;
            }
        }
        tempVec.push_back(tempLen);
    }
    for(int i = 0, len = tempVec.size(); i < len; i++)
    {
        res += tempVec[i] * tempVec[i];
    }
    cout<<res<<endl;
    return 0;
}
