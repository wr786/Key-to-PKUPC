

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

int castle[105][105];
int walls[105][105];
int m, n;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int cnt, maxblocks;
int vis[105][105];
int counter[10001];

void search(int x, int y, int color) {
	for(int dir=0; dir<4; dir++) {
		int nx = x + dx[dir], ny = y + dy[dir];
		if(nx < 1 || nx > 2*m-1 || ny < 1 || ny > 2*n-1) continue;
		if(castle[nx][ny] || vis[nx][ny]) continue;
		vis[nx][ny] = color;
		search(nx, ny, color);
	}
}


int main() {
	m = read(), n = read();
	for(int i=1; i<=2*m-1; i+=2)
		for(int j=1; j<=2*n-1; j+=2) {
			walls[i][j] = read();
			for(int dir=0; dir<4; dir++) {
				if(walls[i][j] & (1<<dir)) { // 该方向有墙
					int x = i + dx[dir], y = j + dy[dir];
					castle[x][y] = 1; // 墙
				}
			}
		}

	for(int i=0; i<=2*m; i+=2)
		for(int j=0; j<=2*n; j+=2)
			castle[i][j] = 1; // 拐角处
	for(int j=0; j<=2*n; j++)
		castle[0][j] = castle[2*n][j] = 1;
	for(int i=0; i<=2*m; i++)
		castle[i][0] = castle[i][2*n] = 1;
	// DEBUG
	// for(int i=0; i<=2*m; i++) {
	// 	for(int j=0; j<=2*n; j++)
	// 		cout << castle[i][j] << " ";
	// 	cout << endl;
	// }

	for(int i=1; i<=2*m-1; i+=2)
		for(int j=1; j<=2*n-1; j+=2) {
			if(castle[i][j] == 0 && !vis[i][j]) {
				cnt++;
				vis[i][j] = cnt;
				search(i, j, cnt);
			}
		}

	for(int i=1; i<=2*m-1; i+=2)
		for(int j=1; j<=2*n-1; j+=2)
			counter[vis[i][j]]++;

	for(int i=1; i<=cnt; i++)
		maxblocks = max(maxblocks, counter[i]);

	printf("%d\n%d\n", cnt, maxblocks);
	return 0;
}
