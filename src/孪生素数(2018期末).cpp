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
int vis[10001];

int main() {
	int m = read();
	for(int i=2; i*i<=m; i++) {
		if(!vis[i]) {
			for(int j=2*i; j<=m; j+=i)
				vis[j] = 1;
		}
	}
	for(int i=m-2; i>1; i--) {
		if(vis[i] == 0 && vis[i+2] == 0) {
			printf("%d %d\n", i, i+2);
			return 0;
		}
	}
}
