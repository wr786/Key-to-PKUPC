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
int n, a[1001][1001];
int prefix[1001][1001];
int ans = -INF; int x1, x2, Y1, y2;

int main() {
  n = unsign_read();
  FOR(i,1,n) FOR(j,1,n) a[i][j] = read();
  FOR(i,1,n) FOR(j,1,n) prefix[i][j] = prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1] + a[i][j];
  FOR(i1,1,n) FOR(j1,1,n) FOR(i2,i1,n) FOR(j2,j1,n) {
    int tmpsum = prefix[i2][j2] - prefix[i1-1][j2] - prefix[i2][j1-1] + prefix[i1-1][j1-1];
    if(tmpsum > ans) {
      ans = tmpsum;
      x1 = i1, x2 = i2, Y1 = j1, y2 = j2;
    }
  }
  FOR(i,x1,x2) {
    printf("%d", a[i][Y1]);
    FOR(j,Y1+1,y2) printf(" %d", a[i][j]);
    printf("\n");
  }
  printf("%d\n", ans);
  return 0;
}
