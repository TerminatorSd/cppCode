/**
 * @author shaoDong
 * @email scut_sd@163.com
 * @create date 2018-08-27 07:43:16
 * @modify date 2018-08-27 07:43:16
 * @desc 小红有两个长度为n的排列A和B。每个排列由[1,n]数组成，且里面的数字都是不同的。
         现在要找到一个新的序列C，要求这个新序列中任意两个位置(i,j)满足:
         如果在A数组中C[i]这个数在C[j]的后面，那么在B数组中需要C[i]这个数在C[j]的前面。
         请问C序列的长度最长为多少呢？
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 判断将a 加入arr 后能否让其中的所有元素对满足条件
bool isFine(vector<int> &arr, int a, vector<int> arrA, vector<int> arrB) 
{
    for(vector<int>::iterator it = arr.begin(); it != arr.end(); it++) 
    {
        // find 方法可以在vector 中找到指定的值
        if((find(arrA.begin(), arrA.end(), *it) > find(arrA.begin(), arrA.end(), a)
            && find(arrB.begin(), arrB.end(), *it) < find(arrB.begin(), arrB.end(), a))
            || (find(arrA.begin(), arrA.end(), *it) < find(arrA.begin(), arrA.end(), a)
            && find(arrB.begin(), arrB.end(), *it) > find(arrB.begin(), arrB.end(), a))) 
        {
            continue;
        }
        else 
        {
            return false;
        }
    }
    arr.push_back(a);
    return true;
}

int printVec(vector<int> arr) {
    for(vector<int>::iterator it = arr.begin(); it != arr.end(); it++) 
    {
       cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
} 

int main(int argc, char const *argv[])
{
    int n, temp, output;
    vector<int> arrA, arrB, middle, res;
    // 输入
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>temp;
        arrA.push_back(temp);
    }
    for(int i = 0; i < n; i++) {
        cin>>temp;
        arrB.push_back(temp);
    }
    // 对于每一个元素，判断是否可以与其他元素共同存在于C 序列中
    for(vector<int>::iterator it = arrA.begin(); it != arrA.end(); it++) 
    {
        middle.push_back(*it);
        for(vector<int>::iterator it2 = arrA.begin(); it2 != arrA.end(); it2++) 
        {
            if(it2 != it) 
            {
                isFine(middle, *it2, arrA, arrB);
            }
        }
        res.push_back(middle.size());
        middle.clear();
    }
    // 找到最长序列值
    output = res[0];
    for(vector<int>::iterator it = res.begin(); it != res.end(); it++) {
        if(*it > output) {
            output = *it;
        }
    }

    cout<<output<<endl;
    return 0;
}
