#include <iostream> 

using namespace std;

int getAllIp(string ip)
{
    int len = ip.size();
    if(len < 4 || len > 12)
    {
        return 0;
    }
    else 
    {
        return 3;
    }
}

int main() {
    int res = 0;
	string ip;
    // input
	cin>>ip;
    res = getAllIp(ip);
	cout<<res<<endl;
	return 0;
}