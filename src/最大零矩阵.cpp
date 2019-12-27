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
int m, n;
int a[101][101], presum[101][101];
int main() {
  m = unsign_read(), n = unsign_read();
  FOR(i,1,m) FOR(j,1,n) a[i][j] = unsign_read();
  FOR(i,1,m) FOR(j,1,n) presum[i][j] = presum[i-1][j] + presum[i][j-1] - presum[i-1][j-1] + (a[i][j] == 0? 1 : -786);
  int maxzero = 0;
  FOR(X1,1,m) FOR(X2,X1,m) FOR(Y1,1,n) FOR(Y2,Y1,n) {
    int zerosum = presum[X2][Y2] - presum[X1-1][Y2] - presum[X2][Y1-1] + presum[X1-1][Y1-1];
    maxzero = max(maxzero, zerosum);
  }
  printf("%d\n",maxzero);
}
