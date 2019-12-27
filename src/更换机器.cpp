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

struct Researcher {
  string namae;
  string pasokonn;
  string nichi;
  string type;
} r[101];

int main() {
    int n = unsign_read();
    FOR(i,1,n) {
      cin >> r[i].namae >> r[i].pasokonn >> r[i].nichi >> r[i].type;
      bool canChange = true;
      if(atoi(r[i].nichi.substr(0,4).c_str()) > 2009) canChange = false;
      else if(atoi(r[i].nichi.substr(0,4).c_str()) == 2009) {
        if(atoi(r[i].nichi.substr(5,2).c_str()) > 3) canChange = false;
        else if(atoi(r[i].nichi.substr(5,2).c_str()) == 3) {
          if(atoi(r[i].nichi.substr(8,2).c_str()) > 1) canChange = false;
        }
      }
      cout << r[i].namae;
      if(!canChange) cout << " ToT\n";
      else {
        cout << " " << (r[i].pasokonn == "Lenovo"? "Dell" : "Lenovo") <<
                " " << (r[i].type == "Desktop"? "Laptop" : "Desktop") << endl;
      }
    }
}
