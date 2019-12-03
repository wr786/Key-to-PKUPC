

#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
#include<string>
using namespace std;
inline int read() {
	int ret = 0, sign = 1;
	char c = getchar();
	while(c == ' ' || c == '\n') c = getchar();
	if(c == '-') {
		sign = -1;
		c = getchar();
	}
	while('0' <= c && c <= '9') {
		ret = ret * 10 + c - '0';
		c = getchar();
	}
	return sign * ret;
}

int n, m;
int canvas[201][201];
int vis[291][201], cnt;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void search(int x, int y) {
	for(int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
		if(!canvas[nx][ny]) continue;
		if(vis[nx][ny]) continue;
		vis[nx][ny] = 1;
		search(nx, ny);
	}
}

int main() {
	n = read(), m = read();
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++) {
			// char c; scanf(" %c", &c);
			// if(c == '#') canvas[i][j] = 1;
			canvas[i][j] = read();
		}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++) {
			if(canvas[i][j] && !vis[i][j]) {
				cnt++;
				vis[i][j] = 1;
				search(i, j);
			}
		}
	printf("%d\n", cnt);
	return 0;
}
