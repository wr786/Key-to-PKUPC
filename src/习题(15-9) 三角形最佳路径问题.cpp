#include<cstdio>
#include<algorithm>
using namespace std;
int n, a[101][101], d[101][101];

int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=i; j++) {
			scanf("%d", &a[i][j]);
		}
	for(int j=1; j<=n; j++)
		d[n][j] = a[n][j];
	for(int i=n-1; i; i--)
		for(int j=i; j; j--)
			d[i][j] =  max(d[i+1][j], d[i+1][j+1]) + a[i][j];
	printf("%d\n",d[1][1]);
	return 0;
}
