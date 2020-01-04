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

int main() {
	int upper = 0, lower = 0;
	string str; getline(cin, str);
	int len = str.length();
	FOR(i,0,len-1) {
		if(isalpha(str[i]) ) {
			if( isupper(str[i]))
				upper ++;
			if(islower(str[i]))
				lower ++ ;
		}
	}
	cout << upper << " " << lower << endl;
	return 0;
}