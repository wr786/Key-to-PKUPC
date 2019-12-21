

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

int dp[41];

int main() {
	int m = read();
	// init
	dp[1] = dp[2] = 1;
	dp[3] = 2;
	dp[4] = 3;  // 1+1+1+1, 1+3, 3+1
	dp[5] = 5; // 1+1+1+1+1, 1+3+1, 1+1+3, 3+1+1, 5
	for(int i=6; i<=m; i++)
		dp[i] = dp[i-1] + dp[i-3] + dp[i-5];
	printf("%d\n", dp[m]);
	return 0;
}
