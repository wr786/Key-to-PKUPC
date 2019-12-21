include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
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
int m, n, a[101][101];
int dp[101][101];
int ans;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int DP(int x, int y) {
  if(dp[x][y] > 1) return dp[x][y];
  FOR(dir,0,3) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(nx < 1 || nx > m || ny < 1 || ny > n) continue;
    if(a[nx][ny] < a[x][y]) dp[x][y] = max(dp[x][y], DP(nx, ny) + 1);
  }
  return dp[x][y];
}

int main() {
  m = unsign_read(), n = unsign_read();
  FOR(i,1,m)
    FOR(j,1,n) {
      a[i][j] = unsign_read();
      dp[i][j] = 1;
    }
  FOR(i,1,m)
    FOR(j,1,n) {
      ans = max(ans, DP(i,j));
    }
  printf("%d\n", ans);
}
