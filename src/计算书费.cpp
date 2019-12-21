#include<cstdio>
int a[100001];
int main()
{
	int k;scanf("%d",&k);
	while(k--)
	{
		for(int i=1;i<=10;i++)
			scanf("%d",&a[i]);
		double sum=28.9*a[1]+32.7*a[2]+45.6*a[3]+78*a[4]+35*a[5]+86.2*a[6]+27.8*a[7]+43*a[8]+56*a[9]+65*a[10];
		printf("%.2lf\n",sum);
	}
	return 0;
}