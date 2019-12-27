// POJ 2528
#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
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
#define lson (o<<1)
#define rson ((o<<1)|1)
#define mid ((l+r)>>1)
#define N 10001000
int st[N<<2];
int x[N], y[N], id[N], idx, num; // id是所有点离散化吼的数组, num是去重后的所有离散点的个数
bool vis[N];
int lastUsed, cnt;

inline void pushdown(int o) {
  if(st[o]) {
    st[lson] = st[o];
    st[rson] = st[o];
    st[o] = 0;
  }
}

void update(int o, int l, int r, int ql, int qr, int color) {
  if(l > r || l > qr || r < ql) return;
  if(ql <= l && r <= qr) {st[o] = color; lastUsed = max(lastUsed, 0); return;}
  pushdown(o);
  update(lson,l,mid,ql,qr,color);
  update(rson,mid+1,r,ql,qr,color);
}

void query(int o, int l, int r) {
  if(st[o]) {
    if(!vis[st[o]]) {
      cnt++;
      vis[st[o]] = true;
    }
    return;
  }
  if(l == r) return; // 叶子
  // pushdown(o);
  query(lson, l, mid);
  query(rson, mid+1, r);
}

inline int getID(int x) {
  int l = 1, r = num;
  while(l <= r) {
    if(id[mid] == x) return mid;
    if(x < id[mid]) r = mid - 1;
    else l = mid + 1;
  }
  return -1;
}

int main() {
  int T = unsign_read(); // 因为使用了离散化，所以这个根本没用（
  while(T--) {
    cnt = 0;
    idx = 0;
    FOR(i,1,lastUsed) st[i] = 0; // init
    lastUsed = 0;
    int n = unsign_read();
    FOR(i,1,n) {
      x[i] = unsign_read(), y[i] = unsign_read();
      id[++idx] = x[i], id[++idx] = y[i];
      // id[++idx] = x[i]-1, id[++idx] = y[i]-1;
      // id[++idx] = x[i]+1, id[++idx] = y[i]+1;
      if(y[i] > x[i] + 1) id[++idx] = x[i] + 1;
    }
    sort(id+1, id+1+idx);
    num = unique(id+1, id+1+idx) - (id+1);
    FOR(color,1,n) { // 倒序剪枝
      vis[color] = false; // init
      int xx = getID(x[color]), yy = getID(y[color]);
      update(1, 1, num, xx, yy, color);
    }
    query(1, 1, num);
    printf("%d\n", cnt);
  }
}
