/**
 * @author shaoDong
 * @email scut_sd@163.com
 * @create date 2018-09-03 07:39:07
 * @modify date 2018-09-03 07:39:07
 * @desc 字典序问题
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

int main()
{
    int n, t;
    int pos, temp;
    vector<int> inputs;
    // 存放阶乘值
    vector<int> fac;
    fac.push_back(1);
    // input
	cout<<"请输入元素的个数,以及一个序列"<<endl;
    cin>>n;
    for(int i = 0;i < n; i++)
    {
        cin>>temp;
        inputs.push_back(temp);
        // 初始化阶乘数组
        if(i >= 1) {
            fac.push_back(fac[i - 1] * i);
        }
    }
    // 如果只输入一个元素
    if(n == 1) 
    {
        cout<<0<<endl<<inputs[0]<<endl;  
    }
    // 如果输入两个以上元素
    else if(n >= 2)
    {
        pos = 0;
        for(int i = 0,k = n - 1;i < n-1; i++,k--)
        {
            // t 代表当前元素之前比该元素小的元素的个数
            t = 0;
            for(int j = 0;j < i; j++)
            {
                if(inputs[j] < inputs[i])
                {
                    t++;
                } 
            }
            // inputs[i] - 1 - t 表示该元素需要向后移动的位数
            pos += (inputs[i] - 1 - t) * fac[k];
        }
        cout<<"该序列是第"<<pos<<"个"<<endl;

        int i;
        // 开始计算下一个序列
        for(i = n - 2; i >= 0; i--)
        {
            // 找到第一个左临小于右临的位置
            if(inputs[i] < inputs[i + 1])
            {
                int j = i;
                // 找到右边第一个大于j 元素的位置
                for(int k = n-1; k > j; k--)
                {
                    if(inputs[k] > inputs[j])
                    {
                        swap(&inputs[j], &inputs[k]);
                        j++;
                        for(int h = n - 1; j < h; j++, h--) 
                        {
                            swap(&inputs[j], &inputs[h]);
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
                swap(&inputs[j], &inputs[k]);
            }
        }
        cout<<"该序列的下一个序列是："<<endl;
        for(int i = 0; i < n; i++)
        {
            cout<<inputs[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
