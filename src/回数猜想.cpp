

#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
#include<string>
using namespace std;
inline int read() {
	int ret = 0, sign = 1;
	char c = getchar();
	while(c == ' ' || c == '\n') c = getchar();
	if(c == '-') {
		sign = -1;
		c = getchar();
	}
	while('0' <= c && c <= '9') {
		ret = ret * 10 + c - '0';
		c = getchar();
	}
	return sign * ret;
}

bool check(string str) {
	int len = str.length();
	for(int i=0; i<len/2; i++)
		if(str[i] != str[len-1-i])
			return false;
	return true;
}

string addRev(string str) {
	int len = str.length();
	string ret = str;
	cout << str << "+";
	for(int i=len-1; i>=0; i--) {
		ret[i] = (int)str[i] + (int)str[len-1-i] - '0'; // 要去掉一个0
		cout << str[i];
	}
	for(int i=len-1; i>=0; i--) {
		if(ret[i] > '0' + 9) {
			ret[i] -= 10;
			if(i > 0) {
				ret[i-1] += 1;
			} else {
				ret = "1" + ret;
			}
		}
	}
	cout << "=" << ret << endl;
	return ret;
}

int main() {
	string base; cin >> base;
	for(int i=1; i<=7; i++) {
		base = addRev(base);
		if(check(base)) {
			cout << "Y\n";
			return 0;
		}
	}
	cout << "N\n";
	return 0;
}
