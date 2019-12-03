

#include<cstdio>
#include<algorithm>
#include<iostream>
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

int search(int l, int r) {
	if(l == 1 && r == 1) return 1;
	if(l < r) { // leftChild
		int parent = search(l, r-l);
		return parent<<1;
	} else { // rightChild
		int parent = search(l-r, r);
		return (parent<<1)|1;
	}
}

int main() {
	int T = read();
	while(T--) {
		int p = read(), q = read();
		printf("%d\n", search(p, q));
	}
	return 0;
}
