include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
#pragma GCC optimize(2)
#pragma warning(push,4)
#define FOR(i,start,end) for(int i=start; i<=end; i++)
#define FOR2(i,start,end) for(int i=start; i>=end; i--)
#define INF 0x3f3f3f3f
inline int read() {
  int ret = 0, sign = 1;
  int c = getchar();
  while(c == ' ' || c == '\n') c = getchar();
  if(c == '-') {
    sign = -1;
    c = getchar();
  }
  while('0' <= c && c <= '9') {
    ret = ret*10 + c - '0';
    c = getchar();
  }
  return sign * ret;
}
inline int unsign_read() {
  int ret = 0;
  int c = getchar();
  while(c == ' ' || c == '\n') c = getchar();
  while('0' <= c && c <= '9') {
    ret = ret*10 + c - '0';
    c = getchar();
  }
  return ret;
}
inline int POW(int base, int num) {
  if(num == 0) return 1;
  if(num == 1) return base;
  int half = POW(base, num>>1);
  int ret = half * half;
  if(num | 1) ret *= base;
  return ret;
}
int a[51][51], dp[51][51];
int n, cost;

int main() {
    n = unsign_read(); cost = read(); int tmp = read();
    cost -= tmp;
    FOR(i,1,n) FOR(j,1,n) a[i][j] = read();
    FOR(i,1,n) FOR(j,1,n) {
      if(i == 1 && j == 1) {
        dp[i][j] = a[i][j];
        continue;
      }
      dp[i][j] = INF;
      if(i>1) dp[i][j] = min(dp[i][j], dp[i-1][j]);
      if(j>1) dp[i][j] = min(dp[i][j], dp[i][j-1]);
      dp[i][j] += a[i][j];
    }
    if(dp[n][n] <= cost) printf("YES\n");
    else printf("NO\n");
}
