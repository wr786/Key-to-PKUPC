
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int idx;

bool cmp(int a, int b) {
	if(a%100 != b%100) return a%100 < b%100; // c从小到大
	if((a/100)%100 != (b/100)%100) return (a/100)%100 < (b/100)%100; // b从小到大
	return a/10000 <= b/10000;
}

vector<int> sol;
// map<int, int> vis;

void search(int sum, int a, int b, int c) {
	if(sum == 0) {
		//if(!vis[a*10000 + b*100 + c]) {
			if(a == -1) a = 0;
			if(b == -1) b = 0;
			if(c == -1) c = 0;
			sol.push_back(a*10000 + b*100 + c);
			//vis[a*10000 + b*100 + c]++;
		//}
		return;
	}
	if(a == -1) {
		a = 0;
		search(sum, 0, b, c);
		while(sum >= 1) {
			search(sum-1, a+1, b, c);
			sum -= 1; a++;
		}
	} else if(b == -1) {
		b = 0;
		search(sum, a, 0, c);
		while(sum >= 2) {
			search(sum-2, a, b+1, c);
			sum -= 2; b++;
		}
	} else if(c == -1) {
		c = 0;
		search(sum, a, b, 0);
		while(sum >= 5) {
			search(sum-5, a, b, c+1);
			sum -= 5; c++;
		}
	}
}

int main() {
	int sum; cin >> sum;
	search(sum, -1, -1, -1);
	sort(sol.begin(), sol.end(), cmp);
	for(vector<int>::iterator it = sol.begin(); it!= sol.end(); ++it) {
		printf("%03d% 12d% 12d% 12d\n", ++idx, *it/10000, (*it/100)%100, *it%100);
	}
	return 0;
}
