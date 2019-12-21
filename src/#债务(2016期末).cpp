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
const int money[7] = {0, 100, 50, 20, 10, 5, 1}; // MAP
int debt[4]; // ab, bc, ca
int cash[4][7]; // a,b,c ; 100,50,20,10,5,1
int ans;
int cnt; // 试试看减少参数数量？好像可以加速来着。
#define prune(pos,M) (pos==3?M%10:M%money[pos])
// inline bool prune(int pos, int M) {
//   if(pos == 3) return M % 10 == 0; // double
//   return M % money[pos] == 0;
//   // 例如：能被20整除，显然，如果此时不能被20整除，那么无论怎么流通债务也不能偿还清债务。
// }

void DFS(int pos) {
  if(pos == 0) {
    if(debt[1] == debt[2] && debt[1] == debt[3]) {ans = min(ans, cnt);} // 最终状态
    return;
  }
  if(cnt >= ans-1) return; // prune
  // if(!prune(pos,abs(debt[1] - debt[2])) || !prune(pos,abs(debt[2] - debt[3]))) return;
  if(prune(pos,abs(debt[1] - debt[2])) || prune(pos,abs(debt[2] - debt[3]))) return;
  // debt[3] - debt[1]其实是和这两个等价的，故不考虑
  FOR(p1,1,3) {
    int p2 = p1%3+1, p3 = (p1+1)%3+1; // 1 -> 2 -> 3 -> 1 loop
    FOR(i,0,cash[p1][pos]) {
      FOR(j,0,cash[p1][pos]-i) {
        debt[p1] -= i * money[pos], debt[p3] += j * money[pos]; // i from p1 to p2; j from p1 to p3;
        cnt += i+j;
        DFS(pos-1);
        cnt -= i+j;
        debt[p1] += i * money[pos], debt[p3] -= j * money[pos];
      }
    }
    FOR(i,0,cash[p2][pos])
      FOR(j,0,cash[p3][pos]) {
        debt[p1] += i * money[pos], debt[p3] -= j * money[pos]; // i from p2 to p1; j from p3 to p1;
        cnt += i+j;
        DFS(pos-1);
        cnt -= i+j;
        debt[p1] -= i * money[pos], debt[p3] += j * money[pos];
      }
  }
}

int main() {
  int t = read();
  FOR(_t,1,t) {
    FOR(i,1,3) debt[i] = read();
    FOR(i,1,3) FOR(j,1,6) cash[i][j] = unsign_read();
    ans = INF; cnt = 0;
    DFS(6);
    if(ans == INF) printf("impossible\n");
    else printf("%d\n", ans);
  }
}
