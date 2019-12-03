

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

int k, m;
string base;

string NextKStr(string str) {
	string ret = str;
	int len = str.length();
	int pos = len - 1;
	ret[pos] += 1; // addOne
	while(ret[pos] >= k + '0' && pos > 0) { // upDigit
		ret[pos] -= k;
		ret[--pos] += 1;
	}
	if(ret[0] >= k + '0') {
		ret[0] -= k;
		ret = "1" + ret;
	}
	return ret;
}

int main() {
	scanf("%d,%d,", &k, &m);
	cin >> base;
	int combo = 0;
	for(int i=1; i<=m; i++) {
		base = NextKStr(base);
		if(combo) printf(",");
		cout << base;
		combo++;
		if(combo == 5) {
			combo = 0;
			printf("\n");
		}
	}
	return 0;
}
