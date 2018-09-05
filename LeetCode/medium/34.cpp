/**
 * @author shaoDong
 * @email scut_sd@163.com
 * @create date 2018-09-05 09:07:44
 * @modify date 2018-09-05 09:07:44
 * @desc 在排序数组中查找元素的第一个和最后一个位置，算法时间复杂度为logN
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res;
    res.push_back(-1);
    res.push_back(-1);
    int len = nums.size();
    int mid, low = 0, high = len - 1, lowIndex, highIndex;
    // 二分查找
    while(low <= high) 
    {
        mid = (high + low) / 2;
        if(nums[mid] == target) 
        {
            res.clear();
            lowIndex = highIndex = mid;
            // 往前找最小下标
            if(mid > 0) 
            {   
                while(nums[lowIndex - 1] == target && lowIndex >0) 
                {
                    lowIndex--;
                }
            }
            // 往后找最大下标
            if(mid < len - 1)
            {
                while(nums[highIndex + 1] == target && highIndex < len - 1) 
                {
                    highIndex++;
                }
            }
            res.push_back(lowIndex);
            res.push_back(highIndex);
            break;
        }
        else if(nums[mid] < target)
        {
            low = mid + 1;
        }
        else 
        {
            high = mid - 1;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    /* code */
    int arr[] = {3, 3, 3};
    vector<int> arrVec(arr, arr + 3);
    vector<int> res;
    // get the result
    res = searchRange(arrVec, 3);
    for(int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}
