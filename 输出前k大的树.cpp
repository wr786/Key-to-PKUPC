#include<cstdio>
#include<algorithm>
using namespace std;
int a[1001];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int k;scanf("%d",&k);
	sort(a+1,a+n+1);//直接排序
	for(int i=n;i>n-k;i--)
		printf("%d\n",a[i]);
	return 0;
}