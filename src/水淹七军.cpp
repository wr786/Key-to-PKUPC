

#include<cstdio>
#include<algorithm>
using namespace std;
int m, n;
int h[201][201], vis[201][201];
int ex, ey;
int snum, sx, sy;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

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

void search(int x, int y, int waterh) {
	for(int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir], ny = y + dy[dir];
		if(nx < 1 || nx > m || ny < 1 || ny > n) continue;
		if(vis[nx][ny]) continue;
		if(h[nx][ny] > waterh) continue;
		vis[nx][ny] = 1;
		search(nx, ny, waterh);
	}
}

int main() {
	int k = read();
	while(k--) {
		m = read(), n = read();
		for(int i=1; i<=m; i++)
			for(int j=1; j<=n; j++) {
				h[i][j] = read();
				vis[i][j] = 0; // init
			}
		ex = read(), ey = read();
		snum = read();
		for(int i=1; i<=snum; i++) {
			sx = read(), sy = read();
			search(sx, sy, h[sx][sy]);
		}
		if(vis[ex][ey]) printf("Yes\n");
		else printf("No\n");
	}
}