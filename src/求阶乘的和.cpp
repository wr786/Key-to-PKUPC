#include<cstdio>
int main()
{
	int a;scanf("%d",&a);
	int sum=0;
	for(int i=1;i<=a;i++)
	{
		int tmp=1;
		for(int j=1;j<=i;j++)//算阶乘
			tmp*=j;
		sum+=tmp;
	}
	printf("%d\n",sum);
	return 0;
}