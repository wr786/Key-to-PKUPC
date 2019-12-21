#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

struct patient {
	int id;
	int severe;
} p[101];

int cmp(patient A, patient B) {
	if(A.severe == B.severe)
		return A.id < B.id;
	else
		return A.severe > B.severe;
}

int main() {
	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		for(int i=1; i<=n; i++) {
			p[i].id = i;
			cin >> p[i].severe;
		}
		sort(p+1, p+1+n, cmp);
		int m = min(k, n); cout << m << endl;
		for(int i=1; i<=m; i++) {
			if(i > 1) cout << " ";
			cout << p[i].id;
		}
		cout << endl;
	}
	return 0;
}