/**
 * @author shaoDong
 * @email scut_sd@163.com
 * @create date 2019-08-16 22:40:13
 * @modify date 2019-08-16 22:41:21
 * @desc 类似js的split 方法
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<class S>
// 打印数值类型的vector
int printVector(S s) {
  for(int i = 0; i < s.size(); i++) {
    cout<<s[i]<<endl;
  }
  return 0;
}

void split(vector<string> &res, string s, char c) {
    string temp = "";
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == c) {
            res.push_back(temp);
            temp = "";
        } else {
            temp += s[i];
        }
    }
    if(temp != "") {
        res.push_back(temp);
    }
}

int main(int argc, char const *argv[])
{
    string str = ",a,,a,";
    vector<string> vs;
    split(vs, str, ',');
    printVector(vs);
    return 0;
}
