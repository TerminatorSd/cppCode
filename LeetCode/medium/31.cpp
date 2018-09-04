/**
 * @author shaoDong
 * @email scut_sd@163.com
 * @create date 2018-09-03 08:48:19
 * @modify date 2018-09-03 08:48:19
 * @desc 字典序的下一个排列
*/

#include <iostream>
#include <vector>

using namespace std;

void swap(int *a, int *b)
{
    long long t;
    t = *a;
    *a = *b;
    *b = t;
}

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    // 如果只输入一个元素
    if(n == 1) 
    {
        cout<<0<<endl<<nums[0]<<endl;  
    }
    // 如果输入两个以上元素
    else if(n >= 2)
    {
        int i;
        // 开始计算下一个序列
        for(i = n - 2; i >= 0; i--)
        {
            // 找到第一个左临小于右临的位置
            if(nums[i] < nums[i + 1])
            {
                int j = i;
                // 找到右边第一个大于j 元素的位置
                for(int k = n-1; k > j; k--)
                {
                    if(nums[k] > nums[j])
                    {
                        swap(&nums[j], &nums[k]);
                        j++;
                        for(int h = n - 1; j < h; j++, h--) 
                        {
                            swap(&nums[j], &nums[h]);
                        }
                    }
                }
                break;
            }
        }
        // 如果已经是最后一个排列
        if(i < 0) 
        {
            for(int j = 0, k = n - 1; k > j; k--, j++)
            {
                swap(&nums[j], &nums[k]);
            }
        }
        // cout<<"该序列的下一个序列是："<<endl;
        for(int i = 0; i < n; i++)
        {
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3};
    vector<int> arrVec(arr, arr + 3);
    nextPermutation(arrVec);
    return 0;
}

