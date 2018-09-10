#include <iostream>
#include <vector>
#include <map>
using namespace std;

int m, res = 0;
map< pair<int, int>, int> flagMap;
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

void dealWithPoint(int i, int j, vector< vector< pair<int, int> > > &inputVec, pair<int, int> flagPair)
{
    inputVec[i][j].second = 1;
    if(inputVec[i][j].first == 0 || flagMap[flagPair] == 1)
    {
        return;
    }
    if(((i < m - 1) && (inputVec[i + 1][j].second == 0 && inputVec[i + 1][j].first == 1)) ||
       ((j < m - 1) && (inputVec[i][j + 1].second == 0 && inputVec[i][j + 1].first == 1)) ) 
    {
        if(inputVec[i + 1][j].second == 0 && inputVec[i + 1][j].first == 1)
        {
            dealWithPoint(i + 1, j, inputVec, flagPair);
        }
        if(inputVec[i][j + 1].second == 0 && inputVec[i][j + 1].first == 1)
        {
            dealWithPoint(i, j + 1, inputVec, flagPair);
        }
    }
    else 
    {
        res++;
        flagMap[flagPair] = 1;
        return;
    }
}

int main() 
{
    int temp;
    vector< vector< pair<int, int> > > inputVec;
    vector< pair<int, int> > tempVec;
    // input
    cin>>m;
    for(int i = 0; i < m; i++) 
    {
        for(int j = 0; j < m; j++)
        {
            cin>>temp;
            tempVec.push_back(make_pair(temp, 0));
        }
        inputVec.push_back(tempVec);
        tempVec.clear();
    }
    while(isNotOver(inputVec)) 
    {
        for(int i = 0; i < m; i++) 
        {
            for(int j = 0; j < m; j++)
            {
                if(inputVec[i][j].second == 0)
                {
                    dealWithPoint(i, j, inputVec, make_pair(i, j));
                }
            }
        }
    }
    cout<<res<<endl;
}