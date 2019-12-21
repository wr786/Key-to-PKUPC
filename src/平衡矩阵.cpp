
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int a[8][8], n, minmaxColSum;
int leftbias[8]; // 记录每个矩阵向左移动几次，而并非真实地去移动

void search(int row) {
	if(row == n + 1) { // 计算阶段
		int maxsum = 0;
		for(int col=1; col<=n; col++) {
			int tmpsum = 0;
			for(int r=1; r<=n; r++) {
				tmpsum += a[r][(col + n - leftbias[r] - 1)%n+1];
			}
			maxsum = max(maxsum, tmpsum);
		}
		minmaxColSum = min(minmaxColSum, maxsum);
	} else {
		for(int bias = 0; bias <= n-1; bias++) { // 移动8次等于没移
			leftbias[row] = bias;
			search(row + 1); // 搜索下一层
			leftbias[row] = 0;
		}
	}
}

int main() {
	while("调参真难调！") {
		scanf("%d", &n);
		if(n == -1) return 0;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				scanf("%d", &a[i][j]);
		// init
		for(int i=2; i<=n; i++) leftbias[i] = 0;
		minmaxColSum = 786554453; // INF
		search(2); // 移动第一层相当于移动后面几层，所以可以不用移动第一层
		printf("%d\n", minmaxColSum);
	}
}
