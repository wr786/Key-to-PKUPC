#include<iostream>
using namespace std;
int row, col, a[101][101], vis[101][101];
int dx[4] = {0, 1, 0 ,-1}; // 用来进行位移
int dy[4] = {1, 0, -1, 0};

void printNext(int x, int y, int dir, int cnt) { // dir代表方向
	// 越界状态处理
	if(cnt == row * col) return;
	while( x + dx[dir] > row
		 	|| x + dx[dir] < 1
	 		|| y + dy[dir] > col
	  	|| y + dy[dir] < 1
			|| vis[x + dx[dir]][y + dy[dir]] // 如果被访问过的话自动转向
	) 	dir = (dir + 1) % 4;
	cout << a[x + dx[dir]][y + dy[dir]] << endl;
	vis[x + dx[dir]][y + dy[dir]]++;
	printNext(x + dx[dir], y + dy[dir], dir, cnt + 1);
}

int main() {
	cin >> row >> col;
	for(int i = 1; i <= row; i++)
		for(int j = 1; j <= col; j++)
			cin >> a[i][j];
	cout << a[1][1] << endl; // 先把第一个元素打印出来
	vis[1][1] = 1;
	printNext(1, 1, 0, 1);
	return 0;
}