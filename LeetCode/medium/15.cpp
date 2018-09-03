/**
 * @author shaoDong
 * @email scut_sd@163.com
 * @create date 2018-09-02 10:17:45
 * @modify date 2018-09-02 10:17:45
 * @desc 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？
 *       找出所有满足条件且不重复的三元组。
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector< vector<int> > threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector< vector<int> >res;
    vector<int> temp;
    int len = nums.size();
    for (int i = 0; i < len-2; ++i)
    {
        // 三数之和拆解为两数之和
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
            // 双指针，一个从前向后走，一个从后向前走
            int low = i + 1, high = len - 1;
            int sum = 0 - nums[i];
            while (low < high) {
                if (nums[low] + nums[high] == sum) {
                    temp.clear();
                    temp.push_back(nums[i]);
                    temp.push_back(nums[low]);
                    temp.push_back(nums[high]);
                    res.push_back(temp);
                    //跳过重复值
                    while (low < high && nums[low] == nums[low + 1]) {
                        ++low;
                    }
                    while (low < high && nums[high] == nums[high - 1]) {
                        --high;
                    }
                    ++low;
                    --high;
                } else if (nums[low] + nums[high] < sum) {
                    ++low;
                } else {
                    --high;
                }
            }
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int arr[] = {-1, 0, 1, 2, -1, -4};
    vector<int> arrVec(arr, arr + 6);

    vector< vector<int> > res = threeSum(arrVec);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
