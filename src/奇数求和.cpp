#include<cstdio>
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	int sum=0;
	//暴力求和
	for(int i=m;i<=n;i++)
		if(i%2)//如果是奇数
			sum+=i;
	printf("%d\n",sum);
	return 0;
}