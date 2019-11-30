
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int atoi_char(char c) {
	if(c <= '9') return c - '0';
	else return c - 'A' + 10;
}

char itoa_char(int num) {
	if(num < 10) return num + '0';
	else return num - 10 + 'A';
}

string alter(string str, int p, int q) { // 进制转换函数
	string ret = "", tmp = ""; // init
	while(str.length() != 0) { // 循环往复，直到商为0
		int rem = 0;
		for(int i=0; i<str.length(); i++) { // 除q取余法
			rem = rem * p + atoi_char(str[i]);
			tmp = tmp + itoa_char(rem / q);
			rem %= q;
		}
		ret = itoa_char(rem) + ret; // 倒序输出，甚至包括了输出为0的特例
		int idx = 0;
		while(tmp[0] == '0') tmp = tmp.substr(1, tmp.length()); // 去除前导零
		str = tmp;
		tmp = ""; // init
	}
	return ret;
}

int main() {
	int m; cin >> m;
	while(m--) {
		string str; cin >> str;
		int p1 = str.find(",");
		int p2 = str.find(",", p1+1);
		int p, q;
		if(p1 == 1) p = atoi_char(str[0]);
		else p = atoi_char(str[0]) * 10 + atoi_char(str[1]);
		if(p2 == str.length() - 2) q = atoi_char(str[str.length()-1]);
		else q = atoi_char(str[str.length()-2]) * 10 + atoi_char(str[str.length()-1]);
		// cout << itoa_plus(atoi_plus(str.substr(p1+1,p2-p1-1), p), q) << endl;
		cout << alter(str.substr(p1+1,p2-p1-1), p, q) << endl;
	}
	return 0;
}
