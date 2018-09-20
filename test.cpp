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

// 给定一个字符串，找到该字符串可以形成的能量石的组合
// 比如 aba -> aba abaaba ababa
void makePowerVec(string p, vector<string> &powerVec)
{
    string q = p;
    powerVec.push_back(p);
    reverse(p.begin(), p.end());
    powerVec.push_back(q + p);
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

// 判断一个字符串里是否有能量石
bool havePower(string str, vector<string> &powerVec)
{
    for(int i = 0, len = powerVec.size(); i < len; i++)
    {
        int pos = str.find(powerVec[i]);
        if(pos > -1)
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
    p = "ab";
    // 构建能量石数组
    makePowerVec(p, powerVec);
    // 输出能量石组
    // for(int i = 0, len = powerVec.size(); i < len; i++)
    // {
    //     cout<<powerVec[i]<<endl;
    // }
    // 找出所有能量石的位置，以及能量石的名字
    lenStr = str.size();
    lenP = p.size();
    string copyStr = str;
    // 从abababa 中找出ab 出现的位置
    while(havePower(copyStr, powerVec))
    {
        for(int i = 0, len = powerVec.size(); i < len; i++)
        {
            int pos = copyStr.find(powerVec[i]);
            // find 方法返回size_t 类型变量，可以赋值给int 变量，但是不能与int 变量直接比较
            if(pos > -1)
            {
                vecPair.push_back(make_pair(pos, powerVec[i]));
                // 替换掉已经找出的能量石
                string temp = "";
                for(int j = 0, len = powerVec[i].size(); j < len; j++)
                {
                    temp += '#';
                }
                copyStr.replace(pos, powerVec[i].length(), temp);
            }
        }
    }
    sort(vecPair.begin(), vecPair.end(), cmp);
    // for(int i = 0, len = vecPair.size(); i < len; i++)
    // {
    //     cout<<vecPair[i].first<<","<<vecPair[i].second<<endl;
    // }
    // 寻找连续的能量石
    for(int i = 0, len = vecPair.size(); i < len; i++)
    {
        int tempI = 0;
        tempLen = vecPair[i].second.size();
        for(int j = i; j < len; j++)
        {
            if(vecPair[j].first + vecPair[j].second.size() == vecPair[j + 1].first) 
            {
                tempI += vecPair[j + 1].second.size();
                tempLen += vecPair[j + 1].second.size();
            }
            else
            {
                break;
            }
        }
        tempVec.push_back(tempLen);
        i += tempI - 1;
    }
    // 求能量和
    for(int i = 0, len = tempVec.size(); i < len; i++)
    {
        res += tempVec[i] * tempVec[i];
    }
    cout<<res<<endl;
    return 0;
}
