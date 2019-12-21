#include<cstdio>
int main()
{
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int tmp;scanf("%d",&tmp);
		if(tmp==i)
		{
			printf("%d\n",i);
			return 0;
		}
	}
	printf("N\n");
	return 0;
}