/**
 * @author shaoDong
 * @email scut_sd@163.com
 * @create date 2018-09-07 04:53:11
 * @modify date 2018-09-07 04:53:11
 * @desc 时间限制：C/C++语言 1000MS；其他语言 3000MS
    内存限制：C/C++语言 65536KB；其他语言 589824KB
    题目描述：
    有n个杀手排成一行，每个杀手都有一个不同的编号(编号为1-n)，在每个夜晚，杀手都会行动，如果某个杀手编号大于他右边的杀手的编号，他就会杀死他右边的杀手，杀手是的行动是瞬间的，因此一个人可能某一个夜晚既杀死了别人又被别人杀死，例如3,2,1这个顺序，在第一个夜晚2会杀死1，同时3也会杀死2。
    显而易见，一段时间之后，就不会有人杀或被杀，平安夜也就到来了，请问在平安夜之前有多少个夜晚。
*/

#include <iostream>
#include <vector>

using namespace std;

bool isNotDone(vector<int> &input)
{
    for(int i = input.size() - 1; i > 0; i--) 
    {
        if(input[i] > input[i - 1])
        {
            continue;
        }
        else 
        {
            return true;
        }
    }
    return false;
}

void killKiller(vector<int> &input) {
    for(int i = input.size() - 1; i > 0; i--) 
    {
        if(input[i] < input[i - 1])
        {
            input.erase(input.begin() + i);
        }
    }
}

int main(int argc, char const *argv[])
{
    int n, temp, sum = 0;
    vector<int> inputVec;
    // input
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>temp;
        inputVec.push_back(temp);
    }

    while(isNotDone(inputVec)) 
    {
        sum++;
        killKiller(inputVec);
    }
    cout<<sum<<endl;
    return 0;
}

