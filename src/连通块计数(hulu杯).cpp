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

int a[101][101];
int n, m;
int vis[101][101], idx;
int cnt[10001];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

void search(int x, int y, int color) {
	vis[x][y] = color;
	FOR(dir,0,3) {
		int nx = x + dx[dir], ny = y + dy[dir];
		if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
		if(vis[nx][ny]) continue;
		if(!a[nx][ny]) continue;
		search(nx, ny, color);
	}
}

int main() {
	n = unsign_read(), m = unsign_read();
	FOR(i,1,n) FOR(j,1,m) {
		char c; cin >> c;
		if(c == '.') a[i][j] = 0;
		else if(c == '*') a[i][j] = 1;
	}
	FOR(i,1,n) FOR(j,1,m) {
		if(!vis[i][j] && a[i][j]) {
			search(i, j, ++idx);
		}
	}
	FOR(i,1,n) FOR(j,1,m) {
		cnt[vis[i][j]]++;
	}
	printf("%d\n", idx);
	sort(cnt+1, cnt+1+idx);
	printf("%d", cnt[1]);
	FOR(i,2,idx) printf(" %d", cnt[i]);
	return 0;
}