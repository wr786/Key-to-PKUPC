#include<cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;
#pragma GCC optimize(2)
#pragma warning(push,4)
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
inline int POW(int base, int num) {
  if(num == 0) return 1;
  if(num == 1) return base;
  int half = POW(base, num>>1);
  int ret = half * half;
  if(num | 1) ret *= base;
  return ret;
}
int a[1001][1001];
int vis[1001][1001];
int n;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int xl, yl, xr, yr;

int main() {
  n = read();
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++) {
      a[i][j] = read();
      if(a[i][j] == 0) {
        if(xl == 0 && yl == 0) {
          xl = i, yl = j;
        }
        xr = i, yr = j;
      }
    }
  int cnt = 0;
  for(int i=xl; i<=xr; i++)
    for(int j=yl; j<=yr; j++) {
      if(a[i][j]) cnt++;
    }
  cout << cnt << endl;
  return 0;
}