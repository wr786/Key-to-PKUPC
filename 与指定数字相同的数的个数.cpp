#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n, m, a[101];

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> m;
	int cnt =0;
	for(int i = 1; i <= n; i++)
		cnt += (m == a[i]);
	cout << cnt << endl;
	return 0;
}