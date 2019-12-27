include <cstdio>
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

map<char, int> vis;
map<char, int> vis2;
int main() {
  string s1, s2; cin >> s1 >> s2;
  int len1 = s1.length();
  FOR(i,0,len1) vis[s1[i]]++;
  int len2 = s2.length();
  bool ok = true;
  FOR(i,0,len2) {
    if(vis[s2[i]]-- <= 0) ok = false;
    vis2[s2[i]]++;
  }
  FOR(i,0,len1) {
    if(vis2[s1[i]]-- <= 0) ok = false;
  }
  if(ok) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}
