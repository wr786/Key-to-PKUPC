#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int vis[21][21];

int f(int x, int y) {
	if(x < 0 || !y) return 0;
	if(x <= 1 || y == 1) return 1;
	if(vis[x][y]) return vis[x][y];
	if(y > x) return vis[x][y] = f(x, x);
	// 存在一个空盘 + 所有盘子都非空
	return vis[x][y] = f(x, y-1) + f(x-y, y);
}

int main() {
	int t; cin >> t;
	while(t--) {
		int m, n; cin >> m >> n;
		cout << f(m, n) << endl;
	}
}
