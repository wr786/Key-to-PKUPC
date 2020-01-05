#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <cctype>
#include <cassert>
#define INF 0x3f3f3f3f
#define FOR(i,start,end) for(int i=start; i<=end; i++)
#define FOR2(i,end,start) for(int i=end; i>=start; i--)
#define DEBUG(x) cerr << "\nDEBUG: " << #x << "=" << x << endl
using namespace std;

struct Gift {
	int price;
	int priority;
	bool operator < (const Gift &other) const {return priority > other.priority;}
} g[101];

int n, m;

int main() {
	scanf("%d%d", &n, &m);
	FOR(i,1,n) scanf("%d%d", &g[i].price, &g[i].priority);
	sort(g+1, g+1+n);
	int cnt = 0;
	FOR(i,1,n) {
		if(m < g[i].price) break;
		cnt++;
		m -= g[i].price;
	}
	printf("%d\n", cnt);
	return 0;
}
