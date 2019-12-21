#include<cstdio>
//状态表
int a[5]={0,0,1,0,0};
int b[5]={0,0,0,0,1};
int c[5]={0,1,1,0,1};
int d[5]={0,1,1,1,0};

int main()
{
	for(int i=1;i<=4;i++)//枚举最佳车号
	{
		if(a[i]&&!b[i]&&!c[i]&&!d[i])
		{
			printf("%d\nA",i);
			break;
		}
		if(!a[i]&&b[i]&&!c[i]&&!d[i])
		{
			printf("%d\nB",i);
			break;
		}
		if(!a[i]&&!b[i]&&c[i]&&!d[i])
		{
			printf("%d\nC",i);
			break;
		}
		if(!a[i]&&!b[i]&&!c[i]&&d[i])
		{
			printf("%d\nD",i);
			break;
		}
	}
	return 0;
}