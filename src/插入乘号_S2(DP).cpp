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
int k, len;
string str;
int getNum[11][11];
int dp[11][11][11];
// first => startpoint
// second => length
// third => *s
inline void generate_getNum() {FOR(i,0,len-1) FOR(j,1,len-i) getNum[i][j] = atoi(str.substr(i,j).c_str());}
inline void DP() {
    FOR(curLen,1,len) FOR(curSP,0,len-1) {
      if(curSP + curLen > len) break;
      dp[curSP][curLen][0] = getNum[curSP][curLen];
      FOR(i,1,curLen-1) { // the num of *
        FOR(leftK,0,i-1) {
          int rightK = i-1 - leftK;
          FOR(leftLen,1,curLen-1) {
            dp[curSP][curLen][i] = max(dp[curSP][curLen][i],
                                       dp[curSP][leftLen][leftK] * dp[curSP+leftLen][curLen-leftLen][rightK]);
          }
        }
      }
    }
    printf("%d\n", dp[0][len][k]);
}

int main() {
  cin >> str; k = unsign_read();
  len = str.length();
  generate_getNum();
  DP();
  return 0;
}
