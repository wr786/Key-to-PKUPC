include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cmath>
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
inline int POW(int base, int num) {
  if(num == 0) return 1;
  if(num == 1) return base;
  int half = POW(base, num>>1);
  int ret = half * half;
  if(num | 1) ret *= base;
  return ret;
}
int n;
double sum=0, aver=0;
int a[301];

int main() {
    n = read();
    FOR(i,1,n) {
      a[i] = read();
      sum += a[i];
    }
    aver = sum / n;
    vector<int> output;
    double bias = 0;
    FOR(i,1,n) {
      if((double)fabs(a[i] - aver) > bias) {
        vector<int> empty;
        output = empty;
        output.push_back(a[i]);
        bias = fabs((double)a[i] - aver);
      } else if(fabs((double)a[i] - aver) == bias) {
        output.push_back(a[i]);
      }
    }
    int len = output.size();
    printf("%d", output[0]);
    FOR(i,1,len-1) {
      printf(",%d", output[i]);
    }
    // printf("\n\n%lf", aver);
  return 0;
}
