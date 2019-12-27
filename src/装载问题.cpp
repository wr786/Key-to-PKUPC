include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstring>
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
int n;
struct cargo {
  int val;
  int idx;
  int vis;
} a[100001];
int c1, c2;
long long aSum = 0;
bool canLoad = false;
int first[100001], second[100001], fidx, sidx, aSumRec = INF;

bool cmp(cargo A, cargo B) {return A.val < B.val;}
bool cmp2(cargo A, cargo B) {return A.idx < B.idx;}

void search(int pos) {
  if(aSum <= c2) { // OK
    if(aSum < aSumRec) {
      aSumRec = aSum;
      fidx = 0, sidx = 0;
      sort(a+1, a+1+n, cmp2);
      FOR(i,1,n) {
        if(a[i].vis) first[++fidx] = a[i].val;
        else second[++sidx] = a[i].val;
      }
      canLoad = true;
      sort(a+1, a+1+n, cmp);
    }
    return;
  }
  if(pos > n)
    return;
  if(a[pos].val > c1) return; // prune
  // FOR(i,pos,n) {
  if(c1 >= a[pos].val) {
    c1 -= a[pos].val;
    a[pos].vis = 1;
    aSum -= a[pos].val;
    search(pos+1);
    c1 += a[pos].val;
    a[pos].vis = 0;
    aSum += a[pos].val;
  }
  // }
  search(pos+1);
}

int main() {
  // input
  n = unsign_read();
  FOR(i,1,n) {
    a[i].val = unsign_read();
    a[i].idx = i;
    aSum += a[i].val;
  }
  c1 = unsign_read(); c2 = unsign_read();
  sort(a+1, a+1+n, cmp);
  search(1);
  if(!canLoad) {
    printf("can't find a way to Loading\n");
  } else {
    printf("ok,can load it\n");
    printf("a way is:\n");
    printf("the first trip load:");
    printf("%d", first[1]);
    FOR(i,2,fidx) printf(" %d", first[i]);
    printf("\nthe second trip load:");
    printf("%d", second[1]);
    FOR(i,2,sidx) printf(" %d", second[i]);
  }
  return 0;
}
