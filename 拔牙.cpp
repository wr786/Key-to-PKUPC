

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

int dp[31];

int main() {
	int n = read();
	// init
	dp[1] = 1; // 1
	dp[2] = 2; // 2 || 1 + 1
	for(int i=3; i<=n; i++)
		dp[i] = dp[i-1] + dp[i-2]; // 状态转移方程
	printf("%d\n", dp[n]);
	return 0;
}
