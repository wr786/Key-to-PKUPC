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