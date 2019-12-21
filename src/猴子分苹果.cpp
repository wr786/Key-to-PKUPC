#include<iostream>
using namespace std;
int f[100001];

int main() {
	int n, k; cin >> n >> k;
	for(int w = 1;; w++) {
		f[1] = w * n + k;
		int flag = 1;
		for(int i=2; i<=n; i++)
			if(f[i-1] % (n-1)) {
				flag = 0;
				break;
			} else {
				f[i] = f[i-1] / (n-1) * n + k;
			}
		if(flag) {
			cout << f[n] << endl;
			break;
		}
	}
	return 0;
}
