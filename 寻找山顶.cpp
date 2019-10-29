#include<iostream>
int m, n, a[21][21];
int ansx[401], ansy[401], idx;

int check(int x, int y) {
	int ret = 1;
	if(x - 1 >= 0 && a[x - 1][y] > a[x][y])
		ret = 0;
	if(x + 1 <= m && a[x + 1][y] > a[x][y])
		ret = 0;
	if(y - 1 >= 0 && a[x][y - 1] > a[x][y])
		ret = 0;
	if(y + 1 <= n && a[x][y + 1] > a[x][y])
		ret = 0;
	return ret;
}

int main() {
	std::cin >> m >> n;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			std::cin >> a[i][j];
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			if(check(i, j))
				ansx[++idx] = i,
				ansy[idx] = j;
	for(int i = 1; i <= idx; i++)
		std::cout << ansx[i] << " " << ansy[i] << std::endl;
	return 0;
}