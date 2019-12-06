include<cstdio>
#include<iostream>
#include<map>
#include<cmath>
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
string str[2001];
int n;
string strpre[1001][21];
map<string, int> vis;
map<string, int> concisely;

int main() {
	while(cin >> str[++n]);
	for(int i=1; i<=n; i++) {
		int len = str[i].length();
		for(int j=0; j<len; j++) {
			strpre[i][j+1] = str[i].substr(0, j+1);
			vis[str[i].substr(0, j+1)]++;
			if(j+1 == len) concisely[str[i]] = i;
		}
	}
	for(int i=1; i<=n; i++) {
		cout << str[i] << " ";
		int len = str[i].length();
		bool flag = false;
		for(int j=1; j<=len; j++)  {
			if(vis[strpre[i][j]] == 1) {
				flag = true;
				cout << strpre[i][j];
			} else if(concisely[strpre[i][j]] == i) {
				flag = true;
				cout << strpre[i][j];
			}
			if(flag) break;
		}
		cout << endl;
	}
	return 0;
}
