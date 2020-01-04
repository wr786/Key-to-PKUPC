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

int n;
int isPrime[100001];
int vis[100001];

inline void generatePrimes() {
	for(int i=2; i<=100000; i++) {
		if(!vis[i]) {
			isPrime[i] = 1;
			for(int j=i; j<=100000; j+=i) vis[j] = 1;
		}
	}
}

inline int getRev(int num) {
	int ret = 0;
	while(num) {
		ret = ret*10 + (num%10);
		num /= 10;
	}
	return ret;
}

int main() {
	n = unsign_read();
	generatePrimes();
	int cnt = 0;
	for(int i=2; i<=n; i++) {
		if(isPrime[i]) {
			int rev = getRev(i);
			if(isPrime[rev]) cnt = i;
		}
	}
	cout << cnt << endl;
}