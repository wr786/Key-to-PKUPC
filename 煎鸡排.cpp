#include<iostream>
#include<algorithm>
using namespace std;
int n, k;
int chicken[1001];

int main() {
	cin >> n >> k;
	for(int i=1; i<=n; i++)
		chicken[i] = 2;
	int cnt = 0;
	sort(chicken+1, chicken+1+n);
	while(chicken[n]) {
		for(int i=n; i>=max(n-k+1, 1); i--)
			if(!chicken[i]) break;
			else chicken[i]--;
		cnt++;
		sort(chicken+1, chicken+1+n);
	}
	cout << cnt << endl;
	return 0;
}