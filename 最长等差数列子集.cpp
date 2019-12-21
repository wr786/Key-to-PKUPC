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
int n, nums[5001];
int dp[5001][5001];
int maxd;
// first => start IDX
// second => d

int main() {
  n = unsign_read();
  FOR(i,1,n) nums[i] = unsign_read();
  sort(nums+1, nums+1+n);
  FOR2(i,n,1) FOR(j,1,i-1) {
    int d = nums[i] - nums[j];
    dp[j][d] = dp[i][d] + 1; // calc
    maxd = max(maxd, d);
  }
  int ansStartIdx = 0, ansD = 0, ansLen = 0;
  FOR2(d,maxd,0) FOR2(sp,n,1) {
    if(dp[sp][d] > ansLen) {
      ansStartIdx = sp;
      ansD = d;
      ansLen = dp[sp][d];
    }
  }
  if(ansLen < 2) printf("NO\n");
  else {
    printf("%d", nums[ansStartIdx]);
    if(ansD)
      for(int i=nums[ansStartIdx]+ansD; i <= nums[ansStartIdx]+ansLen*ansD; i+=ansD)
        printf(",%d", i);
    else  // 公差为0的情况，特判
      FOR(i,1,ansLen) printf(",%d", nums[ansStartIdx]);
  }
  return 0;
}
