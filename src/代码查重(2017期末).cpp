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
inline int POW(int base, int num) {
  if(num == 0) return 1;
  if(num == 1) return base;
  int half = POW(base, num>>1);
  int ret = half * half;
  if(num | 1) ret *= base;
  return ret;
}
int n, m;
int if1, switch1, while1, for1;
int if2, switch2, while2, for2;

int main() {
  n = read();
  for(int i=1; i<=n; i++) {
    scanf("\n");
    string code;
    getline(cin, code);
    int pif = code.find("if");
    if(pif >= 0 && pif < code.length() && (pif == code.length()-1 || code[pif+2] == ' ' || code[pif+2] == '(')) if1++;
    int ps = code.find("switch");
    if(ps >= 0 && ps < code.length() && (ps == code.length()-1 || code[ps+6] == ' ' || code[ps+6] == '(')) switch1++;
    int pw = code.find("while");
    if(pw >= 0 && pw < code.length() && (pw == code.length()-1 || code[pw+5] == ' ' || code[pw+5] == '(')) while1++;
    int pf = code.find("for");
    if(pf >= 0 && pf < code.length() && (pf == code.length()-1 || code[pf+3] == ' ' || code[pf+3] == '(')) for1++;
  }
  m = read();
  for(int i=1; i<=m; i++) {
    scanf("\n");
    string code;
    getline(cin, code);
    int pif = code.find("if");
    if(pif >= 0 && pif < code.length() && (pif == code.length()-1 || code[pif+2] == ' ' || code[pif+2] == '(')) if2++;
    int ps = code.find("switch");
    if(ps >= 0 && ps < code.length() && (ps == code.length()-1 || code[ps+6] == ' ' || code[ps+6] == '(')) switch2++;
    int pw = code.find("while");
    if(pw >= 0 && pw < code.length() && (pw == code.length()-1 || code[pw+5] == ' ' || code[pw+5] == '(')) while2++;
    int pf = code.find("for");
    if(pf >= 0 && pf < code.length() && (pf == code.length()-1 || code[pf+3] == ' ' || code[pf+3] == '(')) for2++;
  }
  if((if1 || switch1 || if2 || switch2) && if1 + switch1 == if2 + switch2) cout << "Yes\n";
  else if((while1 || for1 || while2 || for2) && while1 + for1 == while2 + for2) cout << "Yes\n";
  else if(!if1 && !switch1 && !for1 && !while1 && !if2 && !switch2 && !for2 && !while2) cout << "Yes\n";
  else cout << "No\n";
  return 0;
}