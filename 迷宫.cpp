
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n, a[17][17], vis[17][17], sx, sy, ex, ey;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

void search(int x, int y) {
	for(int dir=0; dir<4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if(nx < 1 || nx > n || ny < 1 || ny > n || vis[nx][ny] || !a[nx][ny]) continue;
		vis[nx][ny] = 1;
		search(nx, ny);
	}
}

int main() {
	int m; cin >> m;
	while(m--) {
		cin >> n;
		for(int i=1; i<=n; i++) {
			string tmp; cin >> tmp;
			int l = tmp.length();
			for(int j=0; j<l; j++) {
				if(tmp[j] == 's') {
					sx = i, sy = j + 1;
					a[i][j+1] = 1; // 能走
				} else if(tmp[j] == 'e') {
					ex = i, ey = j + 1;
					a[i][j+1] = 1;
				} else if(tmp[j] == '#') {
					a[i][j+1] = 0; // 不能走
				} else {
					a[i][j+1] = 1;
				}
			}
		}
        for(int i=1; i<=n; i++)
				for(int j=1; j<=n; j++)
					vis[i][j] = 0;
		search(sx, sy);
		if(vis[ex][ey]) cout << "YES\n";
		else cout << "NO\n";
	}
}