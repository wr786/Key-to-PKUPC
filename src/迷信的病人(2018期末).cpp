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

bool isPrime(int x) {
	for(int i=2; i*i<=x; i++)
		if(x % i == 0) return false;
	return true;
}

bool isSqr(int x) {
	if(x == 0) return false;
	int half = sqrt(x);
	return (half*half == x);
}

int main() {
	int m = read(), n = read();
	int cnt = 0;
	for(int i=m; i<=n; i++) {
		if(not isPrime(i/1000000)) continue;
		if(not isSqr(i%1000)) continue;
		int tmp = i; bool flag = true;
		while(tmp > 10) {
			if(tmp % 100 == 13) {
				flag = false;
				break;
			}
			tmp /= 10;
		}
		if(flag) cnt++;
	}
	printf("%d\n", cnt);
}
