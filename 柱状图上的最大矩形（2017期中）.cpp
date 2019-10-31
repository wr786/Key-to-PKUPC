#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int a[20001];

int main() {
	int n; cin >> n;
	for(int i=1; i<=n; i++)
		cin >> a[i];
	//暴力
	int maxArea = 0;
	for(int i=1; i<=n; i++) {
		int m = 2147483647; // MAX_INT
		for(int j=i; j<=n; j++) {
			m = min(m, a[j]);
			maxArea = max(maxArea, m*(j-i+1));
		}
	}
	cout << maxArea << endl;
}