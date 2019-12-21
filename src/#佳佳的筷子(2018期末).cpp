#include<cstdio>
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
int n, k;
int len[5001];
int dp[5001][1667]; // i ~ n区间内，选取了j个tri筷

int sqr(int x) {return x*x;}

int main() {
	n = read(), k = read();
	for(int i=1; i<=n; i++)
		len[i] = read();
	sort(len+1, len+1+n);
	for(int i=n; i; i--)
		for(int j=1; j<=k; j++) {
			if(j*3 > n-i+1) dp[i][j] = 786554453; // INF // i~n内不足够包括j个tri筷
			// 以下必定能够组成j个tri筷
			else if(j*3 == n-i+1) dp[i][j] = dp[i+2][j-1] + sqr(len[i+1]-len[i]); // 总共就那么多筷子，只能选了
			else dp[i][j] = min(dp[i+2][j-1] + sqr(len[i+1]-len[i]), dp[i+1][j]); // 此时拥有选择权，选取或不选取第i个筷子
		}
	printf("%d\n", dp[1][k]);
	return 0;
}
