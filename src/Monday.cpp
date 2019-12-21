#include<cstdio>
int n,a[1001],sum;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int temp;
		scanf("%d",&temp);
		sum+=temp*a[i];
	}
	printf("%d\n",sum);
	return 0;
}