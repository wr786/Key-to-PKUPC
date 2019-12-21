#include<iostream>
#include<algorithm>
using namespace std;
int a[101];

int main() {
	int n; 
	while(cin >> n) {
		if(!n) break;
		for(int i=1; i<=n; i++)
		cin >> a[i];
		sort(a+1, a+1+n);
		cout << a[n/2 + 1] << endl;
	}
	return 0;
}