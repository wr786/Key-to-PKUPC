#include<iostream>
#include<algorithm>
using namespace std;
int a[21][21];
int m, n;

int main() {
	cin >> m >> n;
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	int maxArea = 0;
	for(int i1 = 1; i1 <= m; i1++) 	// 暴力出奇迹
		for(int j1 = 1; j1 <= n; j1++)
			for(int i2 = i1; i2 <= m; i2++)
				for(int j2 = j1; j2 <= n; j2++) {
					int flag = 1;
					for(int i = i1; i <= i2 && flag; i++)
						for(int j = j1; j <= j2 && flag; j++)
							flag = 1 - a[i][j];
					if(flag) maxArea = max(maxArea, (i2 - i1 + 1) * (j2 - j1 + 1));
				}
	cout << maxArea << endl;
	return 0;
}