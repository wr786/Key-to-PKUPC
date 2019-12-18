// 状压DP
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
#define INF 1e9
#define FOR(i,s,e) for(int i=s;i<=e;i++)
int dp[1<<17];
int n, x[17], y[17], S[17][17], lapped[17][17]; // lapped[] stores the points which are between point idx1 & idx2
inline int read() {
  int ret = 0, sign = 1;
  char c = getchar();
  while(c == ' ' || c == '\n') c = getchar();
  if(c == '-') {
    sign = -1;
    c = getchar();
  }
  while('0' <= c && c <= '9') {
    ret = ret * 10 + c - '0';
    c = getchar();
  }
  return sign * ret;
}

int main() {
  while("wr786") {
    n = read();
    if(!n) break;
    // init
    FOR(i,0,n-1) x[i] = read(), y[i] = read();
    FOR(i,0,n-1)
      FOR(j,i+1,n-1) {
        S[i][j] = abs(x[i]-x[j]) * abs(y[i]-y[j]);
        if(x[i]-x[j] == 0) S[i][j] = abs(y[i]-y[j]);
        if(y[i]-y[j] == 0) S[i][j] = abs(x[i]-x[j]);
        if(x[i]-x[j] == 0 && y[i]-y[j] == 0) S[i][j] = 1; // the same points
        // S[j][i] = S[i][j];
        lapped[i][j] = lapped[j][i] = 0; // init;
        int ldx = min(x[i],x[j]), ldy = min(y[i],y[j]);
        int rux = max(x[i],x[j]), ruy = max(y[i],y[j]);
        FOR(k,0,n-1) {
          if(ldx <= x[k] && x[k] <= rux && ldy <= y[k] && y[k] <= ruy)
            lapped[i][j] |= (1<<k);
        }
        // lapped[j][i] = lapped[i][j];
      }

    FOR(points,1,(1<<n)-1)
      dp[points] = INF;
    dp[0] = 0;
    FOR(points,0,(1<<n)-1) {
      FOR(i,0,n-1) {
        FOR(j,i+1,n-1) {
          dp[points|lapped[i][j]] = min(dp[points|lapped[i][j]], dp[points] + S[i][j]);
        }
      }
    }
    printf("%d\n", dp[(1<<n)-1]);
  }
  return 0;
}
