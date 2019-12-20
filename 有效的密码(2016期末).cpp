include <cstdio>
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
inline int POW(int base, int num) {
  if(num == 0) return 1;
  if(num == 1) return base;
  int half = POW(base, num>>1);
  int ret = half * half;
  if(num | 1) ret *= base;
  return ret;
}
int n;


int main() {
  n = read();
  FOR(t,1,n) {
    string pwd; cin >> pwd;
    int len = pwd.length();
    if(len < 6) {
      cout << "Not safe" << endl;
    } else {
      int haveDigit=0, haveUpper=0, haveLower=0, haveothers=0;
      for(int i=0; i<len; i++) {
        if(isdigit(pwd[i])) haveDigit=1;
        else if(islower(pwd[i])) haveLower=1;
        else if(isupper(pwd[i])) haveUpper=1;
        else haveothers=1;
      }
      int types = haveDigit+haveLower+haveUpper+haveothers;
      if(types == 1) {
        cout << "Not safe" << endl;
      } else if(types == 2) {
         cout << "Medium safe\n";
      } else { cout << "Safe\n";}
    }
  }
  return 0;
}
