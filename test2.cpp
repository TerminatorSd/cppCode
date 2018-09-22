#include <iostream>
using namespace std;

int sum=0; //全排列个数

//打印数组内容
void print(int array[],int len){
    for(int i=0; i<len;++i)
        cout<<array[i]<<" ";
    cout<<endl;
}

//实现两数交换
void swap(int* o,int i,int j){
    int tmp = o[i];
    o[i] = o[j];
    o[j] = tmp;
}

//递归实现数组全排列并打印
void permutation(int array[],int len,int index){
    if(index==len){//全排列结束
        ++sum;
        print(array,len);
    }
    else
        for(int i=index;i<len;++i){
            //将第i个元素交换至当前index下标处
            swap(array,index,i);
            //以递归的方式对剩下元素进行全排列
            permutation(array,len,index+1);
            //将第i个元素交换回原处
            swap(array,index,i);
        }
}

int main(){
    int array[] = {1, 2, 3, 4};
    permutation(array,4,0);
    cout<<"sum:"<<sum<<endl;
}