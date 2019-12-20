
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
#define FOR(i,start,end) for(int i=start; i<=end; i++)
#define INF 0x3f3f3f3f
int n, k;
int length[5005];
int dp[5005][2000];

inline int getValue(int pos1, int pos2) {return (length[pos1]-length[pos2])*(length[pos1]-length[pos2]);}

int main() {
  n = read(), k = read();
  for(int i=1; i<=n; i++)
    length[i] = read();
  sort(length+1, length+1+n);
  for(int curPos=n; curPos; curPos--) // curPos..=n
    FOR(curTri,1,k) {
      if(n-curPos+1 < 3*curTri) dp[curPos][curTri] = INF;
      else if(n-curPos+1 == 3*curTri) dp[curPos][curTri] = dp[curPos+2][curTri-1] + getValue(curPos, curPos+1);
      else dp[curPos][curTri] = min(dp[curPos+1][curTri], dp[curPos+2][curTri-1] + getValue(curPos, curPos+1));
    }
  printf("%d\n", dp[1][k]);
}
