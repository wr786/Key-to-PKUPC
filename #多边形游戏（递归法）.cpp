
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int ans = -786554453;
// 直接用vector存整个图算了
// 其中，-19260817代表加号，-786554453代表乘号

void search(int node_num, int g[]) {
	if(node_num == 1) {
		ans = max(ans, g[0]);
		return;
	}
	if(node_num == 2) {
		if(g[1] == -19260817 || g[3] == -19260817) ans = max(ans, g[0]+g[2]);
		if(g[1] == -786554453 || g[3] == -786554453) ans = max(ans, g[0]*g[2]);
		return;
	}
	for(int i=1; i<=2*node_num-3; i+=2) { // 挑选边
		if(g[i] == -19260817) { // 进行加法运算
			int tmp[42];
			for(int j=0; j<2*node_num; j++) tmp[j] = g[j]; // copy
			tmp[i-1] = tmp[i-1] + tmp[i+1];
			for(int j=i; j<2*node_num-2; j++)
				tmp[j] = tmp[j+2]; // 进行删除操作
			search(node_num-1, tmp);
		} else if(g[i] == -786554453) {
			int tmp[42];
			for(int j=0; j<2*node_num; j++) tmp[j] = g[j]; // copy
			tmp[i-1] = tmp[i-1] * tmp[i+1];
			for(int j=i; j<2*node_num-2; j++)
				tmp[j] = tmp[j+2]; // 进行删除操作
			search(node_num-1, tmp);
		}
	}
	// 特殊处理最后一条边
	if(g[2*node_num-1] == -19260817) {
		int tmp[42];
		for(int i=0; i<2*node_num; i++) tmp[i] = g[i]; // copy2
		tmp[0] = tmp[2*node_num-2] + tmp[0];
		search(node_num-1, tmp);
	} else if(g[2*node_num-1] == -786554453) {
		int tmp[42];
		for(int i=0; i<2*node_num; i++) tmp[i] = g[i]; // copy2
		tmp[0] = tmp[2*node_num-2] * tmp[0];
		search(node_num-1, tmp);
	}
}

int main() {
	int n; scanf("%d", &amp;n);
	int graph[42], idx = 0;
	for(int i=1; i<=n; i++) {
		int tmp; char ctmp;
		scanf("%d %c", &amp;tmp, &amp;ctmp);
		graph[idx++] = tmp;
		if(ctmp == '*') graph[idx++] = -786554453;
		else if(ctmp == '+') graph[idx++] = -19260817;
	}
	search(n, graph);
	printf("%d\n", ans);
	return 0;
}
