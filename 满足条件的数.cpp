#include<cstdio>
int main()
{
	int n;scanf("%d",&n);
	int l,h;scanf("%d%d",&l,&h);
	int sum=0;//个数
	for(int i=1;i<=n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		if(l<=tmp&&tmp<=h) sum++;
	}
	printf("%d\n",sum);
	return 0;
}