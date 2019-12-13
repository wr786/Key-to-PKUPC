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
int k[4];

int main() {
  while("这什么鬼题？") {
    for(int i=1; i<=3; i++) k[i] = read();
    if(!k[1] && !k[2] && !k[3]) break;
    string sEncoded;
    cin >> sEncoded;
    int len = sEncoded.length();
    // for(int i=1; i<=3; i++) { // 逆向解密
      string sGroup1, sGroup2, sGroup3;
      int iGroup1[101], iGroup2[101], iGroup3[101];
      int idx1=0, idx2=0, idx3=0;
      for(int j=0; j<len; j++) {
        if('a' <= sEncoded[j] && sEncoded[j] <= 'i') {
          iGroup1[idx1++] = j;
          sGroup1 = sGroup1 + sEncoded[j];
        } else if('j' <= sEncoded[j] && sEncoded[j] <= 'r') {
          iGroup2[idx2++] = j;
          sGroup2 = sGroup2 + sEncoded[j];
        } else {
          iGroup3[idx3++] = j;
          sGroup3 = sGroup3 + sEncoded[j];
        }
      }
      // cout << sEncoded << endl;
      for(int t=0; t<idx1; t++) {
        sEncoded[iGroup1[(t+k[1])%idx1]] = sGroup1[t];
      }
      for(int t=0; t<idx2; t++) {
        sEncoded[iGroup2[(t+k[2])%idx2]] = sGroup2[t];
      }
      for(int t=0; t<idx3; t++) {
        sEncoded[iGroup3[(t+k[3])%idx3]] = sGroup3[t];
      }
      // cout << sGroup1 << " " << sGroup2 << " " << sGroup3 << endl;
    // }
    cout << sEncoded << endl;
  }
  return 0;
}