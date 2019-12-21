include<cstdio>
#include<map>
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

map<int, bool> vis;

int main() {
	int n = read(), k = read();
	for(int i=1; i<=n; i++) {
		int tmp = read();
		vis[tmp] = true;
		if(tmp != k && vis[k-tmp]) {
			printf("yes\n");
			return 0;
		}
	}
	printf("no\n");
}
