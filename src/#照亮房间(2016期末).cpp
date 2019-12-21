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
int x[101], y[101];
int n;
int RX=INF, RY=INF, LX=-INF, LY=-INF; // 可行范围

int main() {
  while(~scanf("%d", &n)) {
    if(!n) break;
    FOR(i,1,n)
      x[i] = read(), y[i] = read();
    RX=INF, RY=INF, LX=-INF, LY=-INF; // init
    bool flag = true;
    // 夹  逼  定  理（迫真）
    FOR(i,1,n) {
      int j = i < n? i+1 : 1;
      if(x[i] == x[j]) { // v
        if(y[i] < y[j]) LX = max(LX, x[i]); // go up
        else RX = min(RX, x[i]);
        if(LX > RX) flag = false;
      } else {
        if(x[i] > x[j]) LY = max(LY, y[i]); // go left
        else RY = min(RY, y[i]);
        if(LY > RY) flag = false;
      }
      if(!flag) break;
    }
    if(flag) printf("Yes\n");
    else printf("No\n");
  }
  return 0;
}
