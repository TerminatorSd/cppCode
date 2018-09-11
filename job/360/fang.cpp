/**
 * @author shaoDong
 * @email scut_sd@163.com
 * @create date 2018-08-27 09:01:42
 * @modify date 2018-08-27 09:01:42
 * @desc 有一个城市需要修建，给你N个民居的坐标X,Y，
 *       问把这么多民居全都包进城市的话，城市所需最小面积是多少（注意，城市为平行于坐标轴的正方形）
*/

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int num, a ,b, width, height, edge;
    int minx, miny, maxx, maxy;
    // 数组的数组，例如[[0, 0], [0, 2]]
    vector< vector<int> > vecArr;
    vector<int> temp;
    // 输入
    cin>>num;
    for(int i = 0; i < num; i++) 
    {
        cin>>a>>b;
        temp.push_back(a);
        temp.push_back(b);
        vecArr.push_back(temp);
        temp.clear();
    }
    // 取初值
    minx = vecArr[0][0];
    maxx = vecArr[0][0];
    miny = vecArr[0][1];
    maxy = vecArr[0][1];
    // 找最大最小坐标值
    for(vector< vector<int> >::iterator it = vecArr.begin() + 1; it != vecArr.end(); it++) {
        if((*it)[0] < minx) 
        {
            minx = (*it)[0];
        } 
        else if((*it)[0] > maxx) 
        {
            maxx = (*it)[0];
        }

        if((*it)[1] < miny) 
        {
            miny = (*it)[1];
        } 
        else if((*it)[1] > maxy) 
        {
            maxy = (*it)[1];
        }
    }
    // 求正方形边长
    width = maxx - minx;
    height = maxy - miny;
    edge = width > height ? width : height;
   
    cout<<(edge * edge)<<endl;
    return 0;
}
