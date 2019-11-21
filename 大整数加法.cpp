
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n;
string a, b;

string Add(string a, string b) {
	int la = a.length(), lb = b.length();
	int l = max(la, lb);
	string ret = (la > lb)? a: b;
	int addDigit = 0;
	for(int i=1; i<=l; i++) { // 在处理倒数第i位
		int na = (la-i >= 0)? a[la-i] - '0' : 0;
		int nb = (lb-i >= 0)? b[lb-i] - '0' : 0;
		ret[l-i] = (na + nb + addDigit) % 10 + '0';
		addDigit = (na + nb + addDigit) / 10;
	}
    if(addDigit) ret = "1" + ret; // 处理进位
    while(ret[0] == '0' &amp;&amp; ret.length() > 1) ret = ret.substr(1,l+1); // 去除前导零并且特判0的情况
	return ret;
}

int main() {
	cin >> n;
	while(n--) {
		cin >> a >> b;
		cout << Add(a, b) << endl;
	}
}