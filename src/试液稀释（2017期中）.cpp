// 线性DP：最长下降子序列
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
double a[101];
int d[101];

int main() {
	int n; cin >> n;
	for(int i=1; i<=n; i++)
		cin >> a[i];
	// 最长下降子序列
	int ret = 1;
	for(int i=1; i<n; i++) {
		d[i] = max(d[i], 1); // 初始化
		for(int j=i+1; j<=n; j++)
			if(a[j] <= a[i]) {
				d[j] = max(d[j], d[i]+1); // 状态转移方程
				ret = max(ret, d[j]);
			}
	}
	cout << ret << endl;
	return 0;
}

// 如果看不懂DP的话可以尝试这种暴力的搜索方法
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
double a[101];
int n, M;
void search(double r, int idx, int cnt) {
	for(int i=idx+1; i<=n; i++) {
		if(a[i] <= r)
			search(a[i], i, cnt+1);
	}
	M = max(M, cnt);
	return;
}

int main() {
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> a[i];
	// 搜索
	search(1, 0, 0);
	cout << M << endl;
}