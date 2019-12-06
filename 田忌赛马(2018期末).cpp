include<cstdio>
#include<iostream>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
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
#define C 200
int n;
int a[1001], b[1001];

int main() {
	while("难！") {
		n = read();
		if(!n) return 0;
		for(int i=1; i<=n; i++)
			a[i] = read();
		for(int j=1; j<=n; j++)
			b[j] = read();
		int cnt = 0;
		sort(a+1, a+1+n);
		sort(b+1, b+1+n);
		int la = 1, ra = n;
		int lb = 1, rb = n;
		while(la <= ra) {
			if(a[ra] > b[rb]) {
				cnt++;
				ra--; rb--;
			} else if(a[ra] < b[rb]) {
				cnt--; // 极限一换一
				la++; rb--;
			} else {
				if(a[la] > b[lb]) {
					cnt++;
					la++; lb++;
				} else if(a[la] <= b[lb]) {
					if(a[la] < b[rb])
						cnt--; // 极限一换一
					la++; rb--;
				}
			}
		}
		// sort(b+1, b+1+n);
		// int pos = 1;
		// while(a[pos] <= b[1] && pos <= n) {
		// 	pos++;
		// }
		// int cnt = 0;
		// for(int i=1; i<=n; i++) {
		// 	if(a[(i+pos-2)%n+1] > b[i])
		// 		cnt++;
		// 	else if(a[(i+pos-2)%n+1] < b[i])
		// 		cnt--;
		// }
		printf("%d\n", cnt*C);
	}
	return 0;
}
