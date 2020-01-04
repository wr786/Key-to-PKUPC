include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <cctype>
#define INF 0x3f3f3f3f
#define FOR(i,start,end) for(int i=start; i<=end; i++)
#define FOR2(i,end,start) for(int i=end; i>=start; i--)
using namespace std;
inline int read() {
	int ret = 0, sign = 1;
	char c = getchar();
	while(c == ' ' || c == '\n') c = getchar();
	if(c == '-') {sign = -1; c = getchar();}
	while(isdigit(c)) {
		ret = ret * 10 + c - '0';
		c = getchar();
	}
	return sign * ret;
}
inline int unsign_read() {
	int ret = 0;
	char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)) {
		ret = ret * 10 + c - '0';
		c = getchar();
	}
	return ret;
}

int isPrime[10001];
int vis[10001];
inline void generatePrimes() {
	for(int i=2; i<=10000; i++) {
		if(!vis[i]) {
			isPrime[i] = 1;
			for(int j=i; j<=10000; j+=i) vis[j] = 1;
		}
	}
}

int k;

inline bool checkValid(int num) {
	int a[10]; fill(a, a+10, 0);
	a[1] = num / 10000000;
	a[2] = (num / 1000000) % 10;
	a[3] = (num / 100000) % 10;
	a[4] = (num / 10000) % 10;
	a[5] = (num / 1000) % 10;
	a[6] = (num / 100) % 10;
	a[7] = (num / 10) % 10;
	a[8] = num % 10;
	FOR(i,2,8) a[i] += a[i-1];
	FOR(i,1,8) if(!isPrime[a[i]]) return false;
	return true;
}

inline int nextDate(int date) {
	int year = date / 10000;
	int month = (date / 100) % 100;
	int day = date % 100;
	switch(month) {
		case 1:case 3:case 5:case 7:case 8:case 10:case 12:
			if(day == 31) {
				day = 1;
				month += 1;
				year += (month-1) / 12;
				month = (month-1) % 12 + 1;
			} else {
				day++;
			}
			break;
		case 4:case 6:case 9:case 11:
			if(day == 30) {
				day = 1;
				month += 1;
				year += (month-1) / 12;
				month = (month-1) % 12 + 1;
			} else {
				day++;
			}
			break;
		case 2:
			int limitDays = 28;
			if(year % 4 == 0 && year % 100) limitDays = 29;
			else if(year % 400 == 0) limitDays = 29;
			if(day == limitDays) {
				day = 1;
				month += 1;
				year += (month-1) / 12;
				month = (month-1) % 12 + 1;
			} else {
				day++;
			}
			break;
	}
	return year * 1e4 + month * 1e2 + day;
}

int main() {
	int k = unsign_read();
	generatePrimes();
	int curDay = 20200104;
	int cnt = 0;
	do{
		if(curDay == 99991231) {
			printf("-1\n");
			return 0;
		}
		if(checkValid(curDay)) {
			cnt++;
			if(cnt == k) {
				printf("%04d/%02d/%02d", curDay/10000, curDay/100%100, curDay%100);
				break;
			}
		}

	} while(curDay = nextDate(curDay));
	return 0;
}