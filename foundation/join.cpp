/**
 * @author shaoDong
 * @email scut_sd@163.com
 * @create date 2019-08-22 22:17:28
 * @modify date 2019-08-22 22:17:28
 * @desc join demo link arr.join in javascript
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string join(vector<int> a, char c) {
    string res;
    return res;
}

int main(int argc, char const *argv[])
{
    string res;
    vector<int> vi;
    vi.push_back(1);
    vi.push_back(2);
    vi.push_back(3);
    vi.push_back(4);
    res = join(vi, ',');
    cout<<res<<endl;
    return 0;
}
