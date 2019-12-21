#include<iostream>
#include<algorithm>
using namespace std;
int a[23], vis[23];

int main() {
	int n; cin >> n;
	for(int i=1; i<=n; i++)
		cin >> a[i];
	int cnt = 0, pos = 0;
	while(pos != n+1) {
		if(pos == 0) {
			if(vis[pos]) {
				cnt++;
				pos++;
			} else {
				vis[pos]++;
				pos++;
			}
		} else if (a[pos] == 0) {
			cnt++;
			pos++;
		} else if(vis[pos] > 1) {
			cnt++;
			pos++;
		} else if (pos + a[pos] < 0) {
			pos = 0;
		} else if (pos + a[pos] > n+1) {
			pos = n+1;
		} else {
			pos = pos + a[pos];
		}
		vis[pos]++;
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}