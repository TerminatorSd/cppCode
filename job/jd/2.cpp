/**
 * @author shaoDong
 * @email scut_sd@163.com
 * @create date 2018-09-09 07:58:47
 * @modify date 2018-09-09 07:58:47
 * @desc A国有n个城市，他们计划修建n-1条长度为1的道路连接两个城市，城市规划已经给出，最终使得n个城市互相连通，
 * 从i城市到j城市有且只有一条唯一路径。
 * 有一家施工队计划承包两段道路的修建工作，要求这两段道路不经过相同的城市(包括路径端点)，
 * 他们可以获得的利润是两段道路长度的乘积，现在要使得利润最大化，问最大能获得多少利润。
*/

#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <limits>
#include <algorithm>

using namespace std;
int roadLen = 0;
vector<int> visitVec;

bool cutAll(map< pair<int, int>, int> &flagMap, vector< vector<int> > &arr)
{
    int len = arr.size();
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j++)
        {
            if(arr[i][j] == 1 && !flagMap[make_pair(i, j)])
            {
                return false;
            }
        } 
    }
    return true;
}

int visitPoint(int i, int j, vector< vector<int> > &arr, vector< vector<int> > &visitFlag)
{
    roadLen++;
    visitFlag[i][j] = 1;
    int len = arr.size();
    int flag = 0;
    for(int k = j; k < len; k++)
    {
        if(!visitFlag[j][k] && arr[j][k] == 1)
        {
            flag = 1;
            visitPoint(j, k, arr, visitFlag);
        }
    }
    if(flag == 0)
    {
        visitVec.push_back(roadLen);
        roadLen = 0;
    }
    return 1;
}

bool allVisited(vector< vector<int> > &arr, vector< vector<int> > &visitFlag)
{
    int len = arr.size();
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j++)
        {
            if(!visitFlag[i][j] && arr[i][j] == 1)
            {
                return false;
            }
        }
    }
    return true;
}

int getNowRes(vector< vector<int> > &arr, vector< vector<int> > &visitFlag)
{
    // 广度优先搜索遍历
    int len = arr.size(), len2;
    int roadNum = 0, res;
    while(!allVisited(arr, visitFlag))
    {
        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j < len; j++)
            {
                if(!visitFlag[i][j] && arr[i][j] == 1)
                {
                    roadNum += 1;
                    visitPoint(i, j, arr, visitFlag);
                }
            }
        }
    }
    if(roadNum == 1)
    {
        res = 0;
    }
    else
    {
        sort(visitVec.begin(), visitVec.end());
        len2 = visitVec.size();
        res = visitVec[len2 - 1] * visitVec[len2 - 2];
    }
    return res;
}

int solve(vector< vector<int> > &arr) {
    int len = arr.size();
    int res = 0, tempRes;
    vector< vector<int> > visitFlag;
    vector<int> tempVec;
    map< pair<int, int>, int> flagMap;
    // init visit flag
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j++)
        {
            tempVec.push_back(0);
        }
        visitFlag.push_back(tempVec);
        tempVec.clear();
    }
    while(!cutAll(flagMap, arr))
    {
        // 切掉一个边看剩下的组合
        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j < len; j++)
            {
                if(arr[i][j] == 1 && !flagMap[make_pair(i, j)])
                {
                    flagMap[make_pair(i, j)] = 1;
                    // 切一个边
                    visitFlag[i][j] = 1; 
                    // 获取当前利润
                    tempRes = getNowRes(arr, visitFlag);
                    if(tempRes > res)
                    {
                        res = tempRes;
                    }
                }
            } 
        }
        // 清空visitFlag
        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j < len; j++)
            {
                visitFlag[i][j] = 0;
            }
        }
    }
	return res;
}

int main() {
    int res;
    int n, x, y;
    vector< vector<int> > twoArr;
    vector<int> tempVec;
    // input
    cin>>n;
    // init two dimensional arr
    for(int i = 0; i <= n; i ++)
    {
        for(int j = 0; j <= n; j++)
        {
            tempVec.push_back(0);
        }
        twoArr.push_back(tempVec);
        tempVec.clear();
    }
    // input edge
    for(int i = 0; i < n - 1; i++)
    {
        cin>>x>>y;
        twoArr[x][y] = 1;
    }

    res = solve(twoArr);
    cout << res << endl;
    
    return 0;

}
