#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
inline int read() {
	int ret = 0, sign = 1;
	char c = getchar();
	while(c == ' ' || c == '\n') c = getchar();
	if(c == '-') {
		sign = -1;
		c = getchar();
	}
	while('0' <= c && c <= '9') {
		ret = ret * 10 + c - '0';
		c = getchar();
	}
	return sign * ret;
}
#define SPAN 500
int n, m;
int head[SPAN], to[SPAN], cap[SPAN], nxt[SPAN], idx=-1;
inline void addEdge(int u, int v, int c) {
	nxt[++idx] = head[u];
	head[u] = idx;
	to[idx] = v;
	cap[idx] = c;
}
int d[SPAN];

bool BFS() {
	for(int i=1; i<=n; i++)
		d[i] = -1;
	queue<int> que; que.push(1);
	d[1] = 0;
	while(!que.empty()) {
		int u = que.front(); que.pop();
		for(int IDX = head[u]; IDX != -1; IDX = nxt[IDX]) {
			int v = to[IDX];
			if(d[v] == -1 && cap[IDX]) {
				d[v] = d[u] + 1;
				if(v == n) {
					return true;
				}
				que.push(v);
			}
		}
	}
	return false;
}

int DFS(int u, int flow) {
	if(u == n || !flow) return flow;
	int flowed = 0;
	for(int IDX = head[u]; IDX != -1; IDX = nxt[IDX]) {
		int v = to[IDX];
		if(d[v] == d[u] + 1 && cap[IDX]) {
			int min_flow = DFS(v, min(flow, cap[IDX]));
			if(min_flow) {
				flowed += min_flow;
				flow -= min_flow;
				cap[IDX] -= min_flow;
				cap[IDX^1] += min_flow;
				if(!flow) break;
			}
		}
	}
	return flowed;
}

inline void Dinic() {
	int max_flow = 0;
	while(BFS()) {
		int flowed = DFS(1, 786554453); // INF
		if(!flowed) break;
		max_flow += flowed;
	}
	printf("%d\n", max_flow);
	return;
}

int main() {
	while(cin >> m >> n) {
		// init
		for(int i=1; i<=n; i++)
			head[i] = -1;
		idx = -1;
		for(int i=1; i<=m; i++) {
			int u = read(), v = read(), c = read();
			addEdge(u, v, c);
			addEdge(v, u, 0);
		}
		Dinic();
	}
	return 0;
}
