#include<iostream>
using namespace std;
int vis[30001];

int main() {
	int n, temp; cin >> n;
	while(n--) {
		cin >> temp;
		vis[temp + 10000]++;
	}
	int idx = 10001;
	while("cqr女装太美了！") {
		if(!vis[idx]) {
			cout << idx - 10000 << endl;
			return 0;
		}
		idx++;
	}
}