/* 
 ============================
 @Author:   shaoDong
 @Version:  1.0
 @DateTime: 2018-04-01 09:01:12
 @Description: print demo
 ============================
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef std::vector<pii> vpii;
typedef std::vector<pis> vpis;

template<class T>
// 打印pair类型的vector
int printPairVector(T t) {
  for(int i = 0; i < t.size(); i++) {
    cout<<t[i].first<<" "<<t[i].second<<endl;
  }
  return 0;
}

template<class S>
// 打印数值类型的vector
int printVector(S s) {
  for(int i = 0; i < s.size(); i++) {
    cout<<s[i]<<endl;
  }
  return 0;
}

template<class M>
// 打印值为pair的map 
int printPairMap (M m) {
  for(int i = 0; i < m.size(); i++) {
    cout<<m[i].first<<" "<<m[i].second<<endl;
  }
  return 0;
}

int main() {
  vector<int> vs;
  vs.push_back(1);
  vs.push_back(2);
  printVector(vs);

  vpii pInt;
  pInt.push_back(make_pair(1, 2));
  printPairVector(pInt);

  // vpis pStr;
  // pStr.push_back(make_pair(1, "asd"));
  // printPairVector(pStr);
 return 0;
}
 