

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

int T, N;
int S[17], vis[17];
bool found = false;

void search(int num) {
	if(found) return;
	if(num == 1) {
		found = true;
		return;
	}
	for(int i=1; i<=N; i++) {
		if(!vis[i] && S[i] != 1 && S[i] != 0 && num % S[i] == 0 ) {
			vis[i] = 1;
			search(num / S[i]);
			vis[i] = 0;
			if(found) break;
		}
	}
}

int main() {
	T = read(), N = read();
	for(int i=1; i<=N; i++)
		S[i] = read();
	if(T != 0 && T != 1) {
		search(T);
		if(found) printf("YES\n");
		else printf("NO\n");
	} else {
		for(int i=1; i<=N; i++)
			if(S[i] == T) {
				printf("YES\n");
				return 0;
			}
		printf("NO\n");
	}
	return 0;
}
