#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int vis[101];

int main() {
	int n; cin >> n;
	for(int i=1; i<=n; i++) {
		int tmp; cin >> tmp;
		vis[tmp]++;
	}
	for(int i=1; i<=n; i++) {
		if(!vis[i])
			cout << i << endl;
	}
	return 0;
}