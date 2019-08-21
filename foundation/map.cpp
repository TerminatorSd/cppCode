/* 
 ============================
 @Author:   shaoDong
 @Version:  1.0
 @DateTime: 2018-03-31 21:28:58
 @Description: map
 ============================
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef map<int, pii> mpii;

// 打印值为pair的map 
void printPairMap (mpii m) {
  mpii::iterator iter;
  for(iter = m.begin(); iter != m.end(); iter++) {
    cout<<iter->first<<": "<<iter->second.first<<", "<<iter->second.second<<endl;
  }
}

int main() {
  map<int, int> mpi;
  mpii pairMap;
  // map插入pair
  pair<int, int> value(3, 5);
  mpi.insert(value);
  mpi[2] = 3;
  // find value
  map<int, int>::iterator iter;
  iter = mpi.find(3);
  if(iter != mpi.end()) {
    cout<<"find res: "<<iter->second<<endl;
  }
  // pair value map
  pairMap['a'] = make_pair(1, 2);
  pairMap[1] = make_pair(1, 3);
  // print pair map
  cout<<"map size: "<<pairMap.size()<<endl;
  printPairMap(pairMap);
  return 0;
}