/**
 * @author shaoDong
 * @email scut_sd@163.com
 * @create date 2018-10-11 15:42:30
 * @modify date 2018-10-11 15:42:30
 * @desc 下一个更大元素，数组循环计数
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) 
{
    vector<int> res;
    int len = nums.size(), flag = 0;
    for(int i = 0; i < len; i++) 
    {
        flag = 0;
        for(int j = i + 1; (j > i && j < len) || (j >= len && j - len < i); j++)
        {
            if(j < len) 
            {
                if(nums[j] > nums[i])
                {
                    flag = 1;
                    res.push_back(nums[j]);
                    break;
                }
            }
            else 
            {
                if(nums[j - len] > nums[i])
                {
                    flag = 1;
                    res.push_back(nums[j- len]);
                    break;
                }
            }
        }
        if(!flag) 
        {
            res.push_back(-1);
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 3};
    vector<int> arrVec(arr, arr + 5);
    vector<int> res = nextGreaterElements(arrVec);
    for(int i = 0, len = res.size(); i < len; i++) 
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}