#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int a[101][101];

int main() {
	int row, col;
	cin >> row >> col;
	for(int i=1; i<=row; i++)
		for(int j=1; j<=col; j++)
			cin >> a[i][j];
	for(int k=2; k<=row+col; k++) //注意到每次和为定值
			for(int i=1; i<=row; i++) {
				int j = k - i;
				if(j < 1) break; // 边界条件
				if(j > col) continue;
				cout << a[i][j] << endl;
			}
	return 0;
}