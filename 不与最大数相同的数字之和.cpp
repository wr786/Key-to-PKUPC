#include<cstdio>
int a[101];
int main()
{
	int n;scanf("%d",&n);
	int m=-99999999;//设个较小的
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>m) m=a[i];
	}
	int sum=0;
	for(int i=1;i<=n;i++)
		if(a[i]<m) sum+=a[i];
	printf("%d\n",sum);
	return 0;
}