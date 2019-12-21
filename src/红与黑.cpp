#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n, m, sx, sy, res;
int a[21][21], vis[21][21];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

void search(int x, int y) {
	for(int i=0; i<4; i++) {
		int x1 = x + dx[i];
		int y1 = y + dy[i];
		if(x1 < 1 || x1 > n) continue;
		if(y1 < 1 || y1 > m) continue;
		if(vis[x1][y1]) continue;
		if(!a[x1][y1]) continue;
		vis[x1][y1] = 1;
		search(x1, y1);
	}
}

int main() {
	while(cin >> m >> n && n && m) {
		res = 0;
		// input
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++) {
				a[i][j] = vis[i][j] = 0;
				char tmp; cin >> tmp;
				if(tmp == '\n') cin >> tmp;
				if(tmp == '.') a[i][j] = 1;
				else if(tmp == '@') {
					a[i][j] == 1;
					sx = i, sy = j;
				}
			}
		// manipulate
		vis[sx][sy] = 1;
		search(sx, sy);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				res += vis[i][j];
		cout << res << endl;
	}
}
