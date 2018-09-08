/**
 * @author shaoDong
 * @email scut_sd@163.com
 * @create date 2018-09-07 05:04:46
 * @modify date 2018-09-07 05:04:46
 * @desc 题目描述：
    华老师的n个学生参加了一次模拟测验，考出来的分数很糟糕，但是华老师可以将成绩修改为[0,100]中的任意值，
    所以他想知道，如果要使所有人的成绩的平均分不少于X分，至少要改动多少个人的分数？
    第一行一个数T，共T组数据（T≤10）
    接下来对于每组数据：
    第一行两个整数n和X。（1≤n≤1000, 0≤X≤100）
    第二行n个整数，第i个数Ai表示第i个学生的成绩。（0≤Ai≤100）
    example:
    2
    5 60
    59 20 30 90 100
    5 60
    59 20 10 10 100
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getSumScore(vector<int> &scoreVec) 
{
    int sum = 0;
    for(int i = 0; i < scoreVec.size(); i++)
    {
        sum += scoreVec[i];
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int n, num, score, temp;
    int nowSumScore, targetSumScore, nowChange;
    vector< pair<int, int> > numAndScore;
    vector< vector<int> > allScore;
    vector<int> tempScore, resVec;
    // input
    cin>>n;
    for(int i = 0; i < n ; i++) 
    {
        cin>>num>>score;
        tempScore.clear();
        numAndScore.push_back(make_pair(num, score));
        for(int j = 0; j < num; j++)
        {
            cin>>temp;
            tempScore.push_back(temp);
        }
        allScore.push_back(tempScore);
    }
    for(int k = 0; k < n; k++) 
    {
        int count = 0, nowChange = 0;
        targetSumScore = numAndScore[k].first * numAndScore[k].second;
        nowSumScore = getSumScore(allScore[k]);
        // 排序
        sort(allScore[k].begin(), allScore[k].end());
        while(nowSumScore < targetSumScore)
        {
            nowSumScore += 100 - allScore[k][count++];
            nowChange++;
        }
        resVec.push_back(nowChange);
       
    }
    for(int m = 0; m < resVec.size(); m++)
    {
        cout<<resVec[m]<<endl;
    }
    return 0;
}
