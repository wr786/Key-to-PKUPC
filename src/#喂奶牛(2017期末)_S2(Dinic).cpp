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
#define SPAN 10000
int S=1, T;
int head[SPAN], to[SPAN], cap[SPAN], nxt[SPAN], idx = -1;
// idx从零开始，这样idx^1即为idx的反向边
inline void addEdge(int u, int v, int c) {
	nxt[++idx] = head[u];
	head[u] = idx;
	to[idx] = v;
	cap[idx] = c;
}

int N, F, D, edgeSum, nodeSum;
int d[SPAN];

bool BFS() {
	for(int i=S; i<=T; i++) {
		d[i] = -1;
	}
	queue<int> que;
  que.push(S);
	d[S] = 0;
	while(!que.empty()) {
		int u = que.front(); que.pop();
		for(int IDX = head[u]; IDX != -1; IDX = nxt[IDX]) {
			int v = to[IDX];
			if(d[v] == -1 && cap[IDX] > 0) {
				d[v] = d[u] + 1;
        if(v == T) return true;
				que.push(v);
			}
		}
	}
	return false;
}

int DFS(int u, int flow) {
	if(u == T || !flow) return flow;
  int flowed = 0;
	for(int IDX = head[u]; IDX != -1; IDX = nxt[IDX]) {
		int v = to[IDX];
		if(d[v] == d[u] + 1 && cap[IDX] > 0) {
			int minFlow = DFS(v, min(flow, cap[IDX]));
      flowed += minFlow;
      cap[IDX] -= minFlow;
      cap[IDX^1] += minFlow;
      flow -= minFlow;
      if(!flow) break;
		}
	}
  return flowed;
}

inline void Dinic() {
	int max_flow = 0;
	while(BFS()) {
    int flow = DFS(S, 786554453);
    if(!flow) break;
    max_flow += flow; // INF
	}
	printf("%d\n", max_flow);
}

int main() {
	N = read(), F = read(), D = read();
  T = S + F + 2*N + D + 1; // 分牛，为了限流
	for(int i=1; i<=T; i++)
		head[i] = -1; // init
	// 建图
  // 0 为 S
  // 1~F 为 Food
  // F+1 ~ F+N 为 Cow
  // F+N+1 ~ F+N+D 为 Drink
  // F+N+D+1 为 T
  // initGraph
  for(int food=1; food<=F; food++) {
    addEdge(S, S+food, 1);
    addEdge(S+food, S, 0);
  }
  for(int drnk=1; drnk<=D; drnk++) {
    addEdge(S+F+2*N+drnk, T, 1);
    addEdge(T, S+F+2*N+drnk, 0);
  }
	for(int i=1; i<=N; i++) {
    addEdge(S+F+i, S+F+N+i, 1);
    addEdge(S+F+N+i, S+F+i, 0);
		int fi = read(), di = read();
		for(int j=1; j<=fi; j++) {
			int food = read();
			addEdge(S+food, S+F+i, 1);
			addEdge(S+F+i, S+food, 0);
		}
		for(int j=1; j<=di; j++) {
			int drnk = read();
			addEdge(S+F+N+i, S+F+2*N+drnk, 1);
      addEdge(S+F+2*N+drnk, S+F+N+i, 0);
		}
	}
	Dinic();
	return 0;
}
