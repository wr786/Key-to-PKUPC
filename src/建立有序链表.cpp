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

struct Node {
  int val;
  Node* NXT;
  Node* PRT;
};

int main() {
  int T = unsign_read();
  scanf(" \n");
  FOR(t,1,T) {
    Node* o = new Node;
    string input; getline(cin, input);
    Node* cur = o, *tmp;
    int posSpace = input.find(" ");
    while(posSpace >= 0 && posSpace < input.length()) {
      cur->val = atoi(input.substr(0,posSpace).c_str());
      Node* nxt = new Node;
      nxt->PRT = cur;
      cur->NXT = nxt;
      cur = nxt;
      input = input.substr(posSpace+1, input.length());
      posSpace = input.find(" ");
    }
    cur->val = atoi(input.c_str());
    cur->NXT = NULL;
    int changeCnt = 0;
    while("还是数组方便！") {
      int maxval = -INF;
      Node* maxNode = NULL;
      cur = o;
      FOR(i,1,changeCnt) cur = cur->NXT;
      while(cur != NULL) {
        if(cur->val > maxval) {
          maxval = cur->val;
          maxNode = cur;
        }
        cur = cur->NXT;
      }
      changeCnt++;
      if(maxNode == NULL) break;
      if(maxNode == o) continue;
      if(maxNode->PRT != NULL) maxNode->PRT->NXT = maxNode->NXT;
      if(maxNode->NXT != NULL) maxNode->NXT->PRT = maxNode->PRT;
      o->PRT = maxNode;
      maxNode->NXT = o;
      o = maxNode;
    }
    cur = o;
    printf("%d", cur->val);
    cur = cur->NXT;
    while(cur != NULL) {
      printf(" %d", cur->val);
      cur = cur->NXT;
    }
    printf("\n");
    scanf(" \n");
  }
}
