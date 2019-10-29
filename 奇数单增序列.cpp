#include<iostream>
#include<algorithm>
using namespace std;
int a[501], n, idx;

int main() {
	cin >> n;
	while(n--) {
		int tmp; cin >> tmp;
		if(tmp % 2) a[++idx] = tmp;
	}
	sort(a + 1, a + 1 + idx);
	for(int i = 1; i <= idx; i++) {
		if(i > 1) cout << ",";
		cout << a[i];
	}
	return 0;
}