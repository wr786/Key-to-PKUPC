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
string S, empty;

bool judgeTF(int l, int r) { // l..r
  if(r == l+1) {
    if(S[l] == 'V') return true;
    else return false;
  }
  // if(S[l] == '(' && S[r-1] == ')') {l++, r--;}
  string str = S.substr(l, r-l);
  int len = str.length();
  bool ret = true, tmp = true;
  int st = 3; // 1 & 2 | <0 ! 3 origin
  int leftCrakets = 0, leftCraketsLeft = 0;
  int rightCrakets = 0;
  int leftCraketPos[1001];
  for(int i=0; i<len; i++) {
    if(str[i] == '(') leftCraketPos[++leftCrakets] = i;
    else if(leftCrakets) {
      if(str[i] == ')') rightCrakets++;
      if(leftCrakets == rightCrakets) {
        tmp = judgeTF(l + leftCraketPos[1]+1, l + i);
        leftCrakets = 0; rightCrakets = 0;
        if(st < 0) tmp = !tmp, st = -st;
        if(st == 3) ret = tmp;
        if(st == 1) ret = ret && tmp;
        if(st == 2) ret = ret || tmp;
       }
    } else {
      if(str[i] == '!') {
        st = -st;
      } else if(str[i] == '&') {
        st = 1;
      } else if(str[i] == '|') {
        st = 2;
      } else if(str[i] == 'V') {
        tmp = true;
        if(st < 0) tmp = !tmp, st = -st;
        if(st == 3) ret = tmp;
        if(st == 1) ret = ret && tmp;
        if(st == 2) ret = ret || tmp;
      } else if(str[i] == 'F') {
        tmp = false;
        if(st < 0) tmp = !tmp, st = -st;
        if(st == 3) ret = tmp;
        if(st == 1) ret = ret && tmp;
        if(st == 2) ret = ret || tmp;
      }
    }
  }
  // cout << str << " : " << ret << endl;
  return ret;
}

int main() {
  string str;
  while(getline(cin, str)) {
    // TRIM
    while(str == "" || str[0] == '\n' || str[0] == '\r') {
      getline(cin, str);
    }
    S = empty;
    int len = str.length();
    for(int i=0; i<len; i++) {
      if(str[i] != ' ') S = S + str[i];
    }
    len = S.length();
    // TRIM end
    // cout << S << endl;
    bool ans = judgeTF(0, len);
    if(ans) cout << "V\n";
    else cout << "F\n";
  }
}
