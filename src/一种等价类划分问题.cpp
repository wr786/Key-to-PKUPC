
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
int f[10001];
int simcls[10001];
vector<int> cls[10001];

int getf(int x) { // 并查集
	if(f[x] == x) return f[x];
	return f[x] = getf(f[x]);
}

int getSumOfDigits(int x) {
	int ret = 0;
	while(x) {
		ret += x % 10;
		x /= 10;
	}
	return ret;
}

int main() {
	int m, n, k; scanf("%d,%d,%d", &m, &n, &k);
	for(int i=m+1; i<n; i++) f[i] = i; // init
	for(int i=m+1; i<n; i++) {
		int digitalSum = getSumOfDigits(i);
		if(digitalSum % k || digitalSum < k) continue;
		if(simcls[digitalSum]) {
			f[i] = simcls[digitalSum];
		} else {
			simcls[digitalSum] = i;
		}
	}
	for(int i=m+1; i<n; i++) {
		cls[getf(i)].push_back(i);
	}
	for(int t=k; t<=36; t+=k) {
		for(int i=0; i<cls[simcls[t]].size(); i++) {
			if(i) printf(",");
			printf("%d", cls[simcls[t]][i]);
		}
		printf("\n");
	}
	return 0;
}
