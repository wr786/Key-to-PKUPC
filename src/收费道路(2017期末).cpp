#include<cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<cmath>
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
int n, m;
int u[101], v[201], pre[201],nxt[201], idx;
int w1[201], w2[201];
int minFee = 786554453;
int aPre[101];
int vis[101];

inline void addEdge(int x, int y, int z, int v1, int v2) {
  nxt[++idx] = u[x];
  u[x] = idx;
  v[idx] = y;
  pre[idx] = z;
  w1[idx] = min(v1, v2);
  w2[idx] = v2;
}

void search(int pos, int fee) {
  if(pos == n) {
    // cout << fee << endl;
    minFee = min(minFee, fee);
    return;
  }
  if(fee > minFee) return;
  aPre[pos]++;
  for(int IDX = u[pos]; IDX; IDX = nxt[IDX]) {
    if(vis[IDX] > 3) continue;
    vis[IDX]++;
    if(aPre[pre[IDX]]) {
      // if(vis[IDX] == 3 && aPre[4]) cout << "OK" << fee << "+" << w1[IDX] << endl;
      search(v[IDX], fee+w1[IDX]);
    } else {
      search(v[IDX], fee+w2[IDX]);
    }
    vis[IDX]--;
  }
  aPre[pos]--;
}

int main() {
  n = read(), m = read();
  for(int i=1; i<=m; i++) {
    int x = read(), y = read(), z = read(), v1 = read(), v2 = read();
    addEdge(x, y, z, v1, v2);
  }
  search(1, 0);
  if(minFee < 786554453) cout << minFee << endl;
  else cout << "impossible\n";
  return 0;
}