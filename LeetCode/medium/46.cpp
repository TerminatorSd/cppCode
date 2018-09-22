/**
 * @author shaoDong
 * @email scut_sd@163.com
 * @create date 2018-09-20 15:44:45
 * @modify date 2018-09-20 15:44:45
 * @desc 给定一个没有重复数字的序列，返回其所有可能的全排列。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void swap(vector<int> &nums, int a, int b)
{
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}

void arrange(vector<int>& nums, int index, vector< vector<int> > &res) {
    int len = nums.size();
    vector<int> tempVec;
    if(index == len)
    {
        for(int i = 0; i < len; i++)
        {
            tempVec.push_back(nums[i]);
        }
        res.push_back(tempVec);
    }
    for(int j = index; j < len; j++)
    {
        // 递归交换元素位置
        swap(nums, j, index);
        arrange(nums, index + 1, res);
        swap(nums, j, index);
    }
}

vector< vector<int> > permute(vector<int>& nums) {
    vector< vector<int> > res;
    arrange(nums, 0, res);
    return res;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4};
    vector<int> arrVec(arr, arr + 4);
    vector< vector<int> > res;
    res = permute(arrVec);
    // 输出结果
    for(int i = 0, len = res.size(); i < len; i++)
    {
        for(int j = 0, len2 = res[i].size(); j < len2; j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

