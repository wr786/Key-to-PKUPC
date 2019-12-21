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
int n;

int main() {
  n = read();
  while(n--) {
    int m = read();
    m++;
    for(m;;m++) {
      int d1 = m / 1000;
      int d2 = (m/100) % 10;
      int d3 = (m/10) % 10;
      int d4 = m % 10;
      if(d1 == d2 || d1 == d3 || d1 == d4) continue;
      if(d2 == d3 || d2 == d4) continue;
      if(d3 == d4) continue;
      cout << m << endl;
      break;
    }
  }
  return 0;
}