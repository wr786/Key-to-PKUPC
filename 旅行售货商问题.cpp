
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int cost[16][16], n;
bool vis[16];
int minCost = 786554453; // INF

void search(int node, int costSum, int cities) {
	if(costSum >= minCost) return; // prune
	if(cities == n) {
		costSum += cost[node][1]; // 返回出发点的费用
		minCost = min(minCost, costSum);
		return;
	}
	for(int i=2; i<=n; i++) // 1可以不用考虑了
		if(!vis[i]) { // 必然不会选到自己
			vis[i] = true;
			search(i, costSum + cost[node][i], cities+1);
			vis[i] = false;
		}
}

int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			scanf("%d", &cost[i][j]);
	// 我打算直接暴力
	vis[1] = true;
	search(1, 0, 1); // 考虑到都是无向边，所以选起点好像没有关系
	printf("%d\n", minCost);
	return 0;
}
