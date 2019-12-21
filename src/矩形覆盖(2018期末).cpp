include<cstdio>
#include<map>
#include<cmath>
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
int x1[501], Y1[501], x2[501], y2[501], idx;
int n;
int a[501][501];

int main() {
	n = read();
	// for(int i=1; i<=n; i++) {
	// 	int op = read();
	// 	if(op == 0) {
	// 		++idx;
	// 		int x1[idx]  = read(), Y1[idx] = read(), x2[idx] = read(), y2[idx] = read();
	// 	} else {
	// 		int qx1 = read(), qY1 = read(), qx2 = read(), qy2 = read();
	// 		bool flag = true;
	// 		for(int j = 1; j<=idx; j++) {
	// 			if(x1[j] <= qx1 && Y1[j] <= qY1 && )
	// 		}
	// 	}
	// }
	// 还是直接暴力吧
	for(int k=1; k<=n; k++) {
		int op = read();
		if(op == 0) {
			++idx;
			x1[idx]  = read(), Y1[idx] = read(), x2[idx] = read(), y2[idx] = read();
			for(int i=x1[idx]; i<=x2[idx]-1; i++)
				for(int j=Y1[idx]; j<=y2[idx]-1; j++)
					a[i][j] = 1;
		} else{
			int qx1 = read(), qY1 = read(), qx2 = read(), qy2 = read();
			bool flag = true;
			for(int i=qx1; i<=qx2-1; i++)
				for(int j=qY1; j<=qy2-1; j++)
					if(!a[i][j]) {
						flag = false;
						break;
					}
			if(flag) printf("Yes\n");
			else printf("No\n");
		}
	}
}
