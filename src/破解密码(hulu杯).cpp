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

inline char decode_char(char c, char b) {
	int y = (b>='a'? b - 'a' : b - 'A' + 26);
	int z = (c>='a'? c - 'a' : c - 'A' + 26);
	int x = (z - y + 52) % 52;
	if(x < 26) return x + 'a';
	else return x - 26 + 'A';
}

inline string decode(string key, string encoded) {
	int l = encoded.length(), lb = key.length();
	FOR(i,0,l-1) {
		encoded[i] = decode_char(encoded[i], key[i%lb]);
	}
	return encoded;
}

int n, m;
int x[1001], y[1001];
string s[1001];

int main() {
	n = unsign_read(), m = unsign_read();
	FOR(i,1,m) x[i] = unsign_read(), y[i] = unsign_read();
	FOR(i,1,n) cin >> s[i];
	FOR2(i,m,1) {
		string decoded = decode(s[x[i]], s[y[i]]);
		s[y[i]] = decoded;
	}
	FOR(i,1,n) cout << s[i] << endl;
	return 0;
}