#include<cstdio>
int a[1000001];
int main() {
	int n; scanf("%d", &n);
	int cnt = n - 1;
	//线性筛
	for(int i = 2; i * i <= n; i++)
		if(!a[i])
			for(int j = i + i; j <= n; j += i)
				if(!a[j])
					cnt--, a[j] = 1;
	printf("%d\n", cnt);
	return 0;
}