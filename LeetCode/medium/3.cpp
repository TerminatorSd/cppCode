/**
 * @author shaoDong
 * @email scut_sd@163.com
 * @create date 2018-09-01 10:02:17
 * @modify date 2018-09-01 10:02:17
 * @desc 给定一个字符串，找出不含有重复字符的最长子串的长度
*/
#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string s) 
{
    int len = s.size(), 
        res = 1,
        loc;
    string temp;
    // 如果是空字符串，直接返回0
    if(s == "") {
        return 0;
    }
    for(int i = 0; i < len; i++) 
    { 
        temp = s[i];
        for(int j = i + 1; j < len; j++) 
        {
            loc = temp.find(s[j]);
            if(loc >= 0) 
            {
                break;
            }
            else 
            {
                temp += s[j];
            }
        }
        // 每一轮结束计算当前无重复字符串的长度
        if(temp.size() > res) 
        {
            res = temp.size();
            temp.clear();
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    string str = "abc";

    int len = lengthOfLongestSubstring(str);
    cout<<len<<endl;
    return 0;
}

