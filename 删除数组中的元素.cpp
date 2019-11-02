#include<cstdio>
int a[100001];
int main()
{
	//input
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int k;scanf("%d",&k);
	//move
	for(int i=1;i<=n;i++)
	{
		//如果后面是连续的话就继续兑换
		int j=1;
		while(a[i]==k&&i+j<=n)
		{
			a[i]=a[i+j];
			a[i+j]=k;
			j++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k) break;//结束
		printf("%d",a[i]);
		if(a[i+1]!=k&&i<n) printf(" ");
	}
	printf("\n");
	return 0;
}