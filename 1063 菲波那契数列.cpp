#include<iostream>
using namespace std;
int f[100001];

int main() {
	f[1] = 1;
	int idx = 2;
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		if(f[n]) cout << f[n] << endl;
		else {
			for(int i=idx; i<=n; i++)
				f[i] = f[i-1] + f[i-2];
			cout << f[n] << endl;
			idx = n+1;
		}
	}
	return 0;
}