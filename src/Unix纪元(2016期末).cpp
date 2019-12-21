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

int main() {
  int seconds;
  while(~scanf("%d", &seconds)) {
    int SEC = seconds % 60;
    seconds /= 60;
    int MIN = seconds % 60;
    seconds /= 60;
    int HUR = seconds % 24;
    int days = seconds / 24;
    int YER = 1970, MON = 1;
    int cntdays = 0;
    bool flag = true;
    for(YER;flag;YER++) {
      for(MON=1; MON<=12 && flag; MON++) {
        switch(MON) {
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					cntdays += 31;
					break;
				case 4:
				case 6:
				case 9:
				case 11:
					cntdays += 30;
					break;
				case 2:
					if(YER%4 == 0 && YER%100 != 0)
						cntdays += 29;
					else if(YER%400 == 0)
						cntdays += 29;
					else
						cntdays += 28;
			}
      if(cntdays >= days) {
        flag = false;
        break;
      }
      }
      if(!flag) break;
    }
    if(cntdays == days) {
      int DAY = 1;
      MON++;
      if(MON > 12) {
        MON -= 12;
        YER++;
      }
      printf("%4d-%02d-%02d %02d:%02d:%02d\n", YER, MON, DAY, HUR, MIN, SEC);
    } else {
      switch(MON) {
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
        cntdays -= 31;
        break;
      case 4:
      case 6:
      case 9:
      case 11:
        cntdays -= 30;
        break;
      case 2:
        if(YER%4 == 0 && YER%100 != 0)
          cntdays -= 29;
        else if(YER%400 == 0)
          cntdays -= 29;
        else
          cntdays -= 28;
      }
      int DAY = days - cntdays + 1;
      printf("%4d-%02d-%02d %02d:%02d:%02d\n", YER, MON, DAY, HUR, MIN, SEC);
    }
  }
}
