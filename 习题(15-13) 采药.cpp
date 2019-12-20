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
int T, M;
int dp[1001];
// fisrt => leftSpace
// second => curPos
struct kusuri {
  int cost;
  int value;
} ksr[101];
// int cmp(kusuri A, kusuri B) {return A.cost <= B.cost;}
// 背包问题
int main() {
  T = unsign_read(), M = unsign_read();
  FOR(i,1,M) ksr[i].cost = unsign_read(), ksr[i].value = unsign_read();
  // sort(ksr+1, ksr+1+M, cmp);
  FOR(j,1,M)
    FOR2(i,T,0) {
      dp[i] = dp[i];
      if(i >= ksr[j].cost)
        dp[i] = max(dp[i-ksr[j].cost]+ksr[j].value, dp[i]);
    }
  printf("%d\n", dp[T]);
  return 0;
}
