#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <cstring>
using namespace std;
#pragma GCC optimize(2)
#pragma warning(push,4)
#define FOR(i,start,end) for(int i=start; i<=end; i++)
#define FOR2(j,start,end) for(int j=start; j>=end; j--)
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
int n, m;
int matrix[81][81];
int dp[81][81];
int ans;
// first => turns
// second => left    =>    right => m - (turn - (left - 1))
#define right m - (turn - (left - 1))
inline void init() {FOR(i,0,m) FOR(j,0,1+m) dp[i][j] = 0;}

int main() {
  n = unsign_read(), m = unsign_read();
  FOR(i,1,n) FOR(j,1,m) matrix[i][j] = unsign_read();
  FOR(curRow,1,n) {
    init(); int maxSum = 0;
    FOR(turn,1,m) FOR(left,1,1+turn) {
      dp[turn][left] = max(dp[turn][left], dp[turn-1][left-1] + matrix[curRow][left-1]*turn); // get from left this turn
      dp[turn][left] = max(dp[turn][left], dp[turn-1][left] + matrix[curRow][right+1]*turn); // get from right this turn
    }
    FOR(left,1,m+1) maxSum = max(maxSum, dp[m][left]);
    ans += maxSum;
  }
  printf("%d\n", ans);
  return 0;
}
