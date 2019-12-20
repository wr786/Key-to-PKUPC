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
int n, a[101];
int lus[101], lds_from_back[101];

int main() {
  n = unsign_read();
  FOR(i,1,n) a[i] = unsign_read();
  FOR(i,1,n) {
    lus[i] = 1;
    FOR(j,1,i-1) {
      if(a[j] < a[i])
        lus[i] = max(lus[i], lus[j] + 1);
    }
  }
  FOR2(i,n,1) {
    lds_from_back[i] = 1;
    FOR2(j,n,i+1)
      if(a[i] > a[j])
        lds_from_back[i] = max(lds_from_back[i], lds_from_back[j] + 1);
  }
  int maxcnt = 0;
  FOR(i,1,n) maxcnt = max(maxcnt, lus[i] + lds_from_back[i] - 1);
  printf("%d\n", n-maxcnt);
  return 0;
}
