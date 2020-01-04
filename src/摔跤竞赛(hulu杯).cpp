include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <cctype>
#define INF 0x3f3f3f3f
#define FOR(i,start,end) for(int i=start; i<=end; i++)
#define FOR2(i,end,start) for(int i=end; i>=start; i--)
using namespace std;
inline int read() {
	int ret = 0, sign = 1;
	char c = getchar();
	while(c == ' ' || c == '\n') c = getchar();
	if(c == '-') {sign = -1; c = getchar();}
	while(isdigit(c)) {
		ret = ret * 10 + c - '0';
		c = getchar();
	}
	return sign * ret;
}
inline int unsign_read() {
	int ret = 0;
	char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)) {
		ret = ret * 10 + c - '0';
		c = getchar();
	}
	return ret;
}

int n, K;
int a[1001];
int cnt;

int main() {
	int T = unsign_read();
	while(T--) {
		n = unsign_read(), K = unsign_read();
		FOR(i,1,n) a[i] = unsign_read();
		cnt = 1; // init
		sort(a+1, a+1+n);
		FOR(i,2,n) {
			if(a[i] - a[i-1] <= K) cnt++;
			else {
				cnt = 1;
			}
		}	
		printf("%d\n", cnt);
	}
	return 0;
}