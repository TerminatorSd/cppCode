// 输入ip 的时候没有输点
// 输入字符串，给出所有可能的ip 组合
#include <iostream> 

using namespace std;
int getAllIp(string ip, int n) {
	int len = ip.size();
    int first, second, third, number, res = 0;
	if (n == 0) {
		if (len > 3 || len < 1) {
			return 0;
		} else if (len == 3) {
			first = ip.at(0) - 48;
			second = ip.at(1) - 48;
			third = ip.at(2) - 48;
			number = first * 100 + second * 10 + third;
			if (number > 255) {
				return 0;
			} else {
				return 1;
			}
		}
		return 1;
	} else if (len / (n + 1) > 3 || len / (n + 1) < 1 || len == 0) {
		return 0;
	}
	first = ip.at(0) - 48;
	second = ip.at(1) - 48;
	res = getAllIp(ip.substr(1, len - 1), n - 1) + getAllIp(ip.substr(2, len - 2), n - 1);
	if (len >= 3) {
		third = ip.at(2) - 48;
		number = first * 100 + second * 10 + third;
		if (number <= 255) {
			res = res + getAllIp(ip.substr(3, len - 3), n - 1);
		}
	}
	return res;
}
int main() {
    int res = 0;
	string ip;
    // input
	cin>>ip;
	res = getAllIp(ip, 3);
	cout<<res<<endl;
	return 0;
}