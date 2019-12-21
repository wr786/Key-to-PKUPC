
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define EMPTY 0
int a[51][51], vis[51][51];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int sx, sy, ex, ey;
int m, n;

void search(int x, int y) {
	for(int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir], ny = y + dy[dir];
		if(nx < 1 || nx > m) continue;
		if(ny < 1 || ny > n) continue;
		if(vis[nx][ny] || (a[nx][ny] != EMPTY)) continue;
		vis[nx][ny] = 1;
		search(nx, ny);
	}
}

int main() {
	cin >> m >> n;
	for(int i=1; i<=m; i++)
		for(int j=1; j<=n; j++) {
			int tmp; cin >> tmp;
			if(tmp == 2) {
				sx = i, sy = j;
				a[i][j] = EMPTY;
			} else if(tmp == 3) {
				ex = i, ey = j;
				a[i][j] = EMPTY;
			} else {
				a[i][j]= tmp;
			}
		}
	search(sx, sy);
	if(vis[ex][ey]) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}
