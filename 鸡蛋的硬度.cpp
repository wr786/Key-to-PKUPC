
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
int n, m;
int dp[101][11];
// first => floorNum
// second => eggNum

int DP(int floorNum, int eggNum) {
  if(floorNum == 0) return 0;
  if(eggNum == 1) return floorNum;
  if(dp[floorNum][eggNum] != 1e9) return dp[floorNum][eggNum];
  int res = 1e9;
  for(int dropFloor=1; dropFloor<=floorNum; dropFloor++) {
    res = min(res,
              max(DP(dropFloor-1, eggNum-1),
                  DP(floorNum-dropFloor, eggNum))     + 1);
  }
  return dp[floorNum][eggNum] = res;
}

int main() {
  while(~scanf("%d%d", &n, &m)) {
    for(int i=1; i<=n; i++)
      for(int j=1; j<=m; j++)
        dp[i][j] = 1e9; // init
    printf("%d\n", DP(n, m));
  }
  return 0;
}
