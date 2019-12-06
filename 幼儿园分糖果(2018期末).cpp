include<cstdio>
#include<iostream>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
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
int n,f;
int Candy2Peo[21][21];
int Candy2PeoNum[21];
int vis[21];
int ans;

void search(int peo, int pos) {
	if(pos > f) {
		ans = max(ans, peo);
		// printf("no");
		return;
	}
	for(int i=1; i<=Candy2PeoNum[pos]; i++) {
		if(!vis[Candy2Peo[pos][i]]) {
			vis[Candy2Peo[pos][i]] = 1;
			search(peo+1, pos+1);
			vis[Candy2Peo[pos][i]] = 0;
		}
	}
	search(peo, pos+1);
}

int main() {
	n = read(), f = read();
	for(int i=1; i<=n; i++) {
		int m = read();
		for(int j=1; j<=m; j++) {
			int candy = read();
			Candy2PeoNum[candy]++;
			Candy2Peo[candy][Candy2PeoNum[candy]] = i;
		}
	}
	search(0, 1);
	printf("%d\n", ans);
	return 0;
}
