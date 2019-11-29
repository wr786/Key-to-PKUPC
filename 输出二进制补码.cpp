
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool isEnd = false;

int read() {
	int ret = 0, sign = 1;
	char c = getchar();
	while(c == ' ' || c == '\n') c = getchar();
	if('a' <= c &amp;&amp; c <= 'z') {
		isEnd = true;
		return 0;
	}
	if('A' <= c &amp;&amp; c <= 'Z') {
		isEnd = true;
		return 0;
	}
	if(c == '-') {
		sign = -1;
		c = getchar();
	}
	while('0' <= c &amp;&amp; c <= '9') {
		ret = ret * 10 + c - '0';
		c = getchar();
	}
	return sign * ret;
}

int main() {
	int n;
	while("wr786") {
		n = read();
		if(isEnd) return 0;
		bool flag = false;
		if(n == -2147483648) { // 特判这个情况，因为我懒得改long long或unsign了
			cout << "10000000000000000000000000000000\n";
			continue;
		}
		if(n < 0) {
			flag = true;
			n *= -1;
		}
		int code[32];
		for(int i=0; i<32; i++) code[i] = 0;
		int idx = 31;
		while(n) {
			code[idx--] = n % 2;
			n /= 2;
		}
		if(flag) {
			for(int i=0; i<32; i++)
				code[i] = 1 - code[i]; // 反转
			code[31] += 1;
			int idxend = 31;
			while(code[idxend] == 2 &amp;&amp; idxend > 0) {
				code[idxend] = 0;
				code[--idxend] += 1;
			}
			// 这里或许应该判断1111111…111 + 1
			// 但是我们已经把0的情况排除了
			// 所以没有必要
		}
		for(int i=0; i<32; i++)
			cout << code[i];
		cout << endl;
	}
}
