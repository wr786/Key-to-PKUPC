#include<cstdio>
int main()
{
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<=a;i++)
		if(i*2+(a-i)*4==b)//脚
		{
			printf("%d %d\n",i,a-i);
			break;
		}
	return 0;
}