#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
map<string, int> id; int idx_people = 0;
int head[20001], to[20001], nxt[20001], idx_line = 0; // 邻接表
int dp[20001][2];
bool flag;

void DP(int pos) {
	dp[pos][1] = 1; int childs = 0;
	for(int idx = head[pos]; idx; idx = nxt[idx]) {
		int j = to[idx]; childs++;
		DP(j);
		dp[pos][0] += max(dp[j][0], dp[j][1]);
		dp[pos][1] += dp[j][0];
	}
	if(dp[pos][0] == dp[pos][1] && (childs > 1 || pos == 1)) flag = false;
}

int main() {
	int n;
	while (scanf("%d", &n)) {
		if (!n) break;
		// initialize
		map<string, int> nul; id = nul;
		idx_people = idx_line = 0;
		for(int i=0; i<=n; i++) {
			head[i] = to[i] = nxt[i] = 0;
		}
		flag = true;
		for (int i=0; i<=n; i++)
			dp[i][0] = dp[i][1] = 0;
		// input
		string boss; cin >> boss;
		id[boss] = ++idx_people; // 1号
		for (int i=1; i<n; i++) {
			string employee, employer;
			cin >> employee >> employer;
			if(id[employer] == 0) id[employer] = ++idx_people;
			if(id[employee] == 0) id[employee] = ++idx_people;
			// addEdge
			nxt[++idx_line] = head[id[employer]];
			to[idx_line] = id[employee];
			head[id[employer]] = idx_line;
		}
		DP(1);
		int ans = max(dp[1][0], dp[1][1]);
		printf("%d ", ans);
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
}