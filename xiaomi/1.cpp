#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const set<int> &se1, const set<int> &se2)
{
    return *se1.begin() - *se2.begin();
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<set<int> > vecs;
    
    for(int i = 0; i < n; i++)
    {
        int j;  
        cin >> j;
        vecs[i].insert(j);
        while (cin.get() != '\n')   { 
            cin >> j; 
            vecs[i].insert(i);
        } 
    }
    sort(vecs.begin(), vecs.end(), cmp);

    vector<int> c;
    auto it = vecs.begin();
    it++;
    auto it1 = vecs.begin();
    for(; it1 != vecs.end(); it1++)
    {        
        set_intersection(it->begin(), it->end(), it1->begin(), it1->end(), back_inserter(c));
        if(c.size() > 0)
        {

        }
    }
    
    return 0;
}
