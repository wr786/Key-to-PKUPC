#include<iostream>
using namespace std;

int f(int x, int lim) {
	int ret = 1;
	for(int i=lim; i*i<=x; i++)
		if(x % i == 0)
			ret += f(x/i, i);
	return ret;
}

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		cout << f(n, 2) << endl;
	}
}
