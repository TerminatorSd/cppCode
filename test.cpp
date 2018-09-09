/**
 * @author shaoDong
 * @email scut_sd@163.com
 * @create date 2018-09-09 10:20:34
 * @modify date 2018-09-09 10:20:34
 * @desc [description]
*/

#include <iostream>
#include <vector>

using namespace std;
int m, res = 0;
bool isNotOver(vector< vector< pair<int, int> > > &inputVec)
{
    int len = inputVec.size();
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j++)
        {
            if(inputVec[i][j].second == 0)
            {
                return true;
            }
        }
    }
    return false;
}

void dealWithPoint(int i, int j, vector< vector< pair<int, int> > > &inputVec)
{
    inputVec[i][j].second = 1;
    if(inputVec[i][j].first == 0)
    {
        return;
    }
    // cout<<inputVec[i + 1][j].second<<","<<inputVec[i + 1][j].first<<endl;
    // cout<<inputVec[i][j + 1].second<<","<<inputVec[i][j + 1].first<<endl;
    if(((i < m - 1) && (inputVec[i + 1][j].second == 0 && inputVec[i + 1][j].first == 1)) ||
       ((j < m - 1) && (inputVec[i][j + 1].second == 0 && inputVec[i][j + 1].first == 1)) ) 
    {
        if(inputVec[i + 1][j].second == 0 && inputVec[i + 1][j].first == 1)
        {
            dealWithPoint(i + 1, j, inputVec);
        }
        else 
        {
            dealWithPoint(i, j + 1, inputVec);
        }
    }
    else 
    {
        res++;
        return;
    }
}

int main() 
{
    int temp;
    vector< vector< pair<int, int> > > inputVec;
    vector< pair<int, int> > tempVec;
    // input
    m = 2;
    tempVec.push_back(make_pair(1, 0));
    tempVec.push_back(make_pair(0, 0));
    inputVec.push_back(tempVec);
    tempVec.clear();
    tempVec.push_back(make_pair(0, 0));
    tempVec.push_back(make_pair(1, 0));
    inputVec.push_back(tempVec);
    // for(int i = 0; i < m; i++) 
    // {
    //     for(int j = 0; j < m; j++)
    //     {
    //         cout<<inputVec[i][j].first;
    //     }
    // }
    // cin>>m;
    // for(int i = 0; i < m; i++) 
    // {
    //     for(int j = 0; j < m; j++)
    //     {
    //         cin>>temp;
    //         tempVec.push_back(make_pair(temp, 0));
    //     }
    //     inputVec.push_back(tempVec);
    // }
    while(isNotOver(inputVec)) 
    {
        for(int i = 0; i < m; i++) 
        {
            for(int j = 0; j < m; j++)
            {
                if(inputVec[i][j].second == 0)
                {
                    dealWithPoint(i, j, inputVec);
                }
            }
        }
    }
    cout<<res<<endl;
}