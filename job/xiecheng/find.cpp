/**
 * @author shaoDong
 * @email scut_sd@163.com
 * @create date 2018-09-05 05:50:17
 * @modify date 2018-09-05 05:50:17
 * @desc 输入编号和起止时间，给定跟一个时间，输入改时间所在范围的编号
*/

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    
    int n, temp, target, res;
    int flag = 0;
    int mid, low, high;
    vector< vector<int> > inputVec;
    vector<int> tempVec;
    // input
    cin>>n;
    cin>>target;
    for(int i = 0; i < n; i++) {
        tempVec.clear();
        for(int j = 0; j < 3; j++) {
            cin>>temp;
            tempVec.push_back(temp);
        }
        inputVec.push_back(tempVec);
    }
    // cout<<inputVec.size()<<endl;
    // find num
    low = 0;
    high = n-1;
    mid = (low + high) / 2;
    while(low <= high) {
        if(inputVec[mid][1] < target && inputVec[mid][2] > target) {
            flag = 1;
            res = inputVec[mid][0];
        } else if(inputVec[mid][2] < target) {
            low = mid + 1;
        } else if(inputVec[mid][1] > target){
            high = mid - 1;
        }
    }
    if(flag) {
        cout<<res<<endl;
    } else {
        cout<<"null"<<endl;
    }

    return 0;
}
