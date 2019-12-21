#include<cstdio>
int r[101][101];
int n;
void alter(int d)
{
	int i2,j2;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(!(r[i][j]>=1&&r[i][j]<=d-1)) continue;
			//四向传染
			i2=i+1,j2=j;
			if(1<=i2&&i2<=n&&1<=j2&&j2<=n&&r[i2][j2]==0)
				r[i2][j2]=d;
			i2=i-1,j2=j;
			if(1<=i2&&i2<=n&&1<=j2&&j2<=n&&r[i2][j2]==0)
				r[i2][j2]=d;
			i2=i,j2=j-1;
			if(1<=i2&&i2<=n&&1<=j2&&j2<=n&&r[i2][j2]==0)
				r[i2][j2]=d;
			i2=i,j2=j+1;
			if(1<=i2&&i2<=n&&1<=j2&&j2<=n&&r[i2][j2]==0)
				r[i2][j2]=d;
		}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			char c;scanf(" %c",&c);
			if(c=='#') r[i][j]=-1;
			if(c=='@') r[i][j]=1;
		}
	int m;scanf("%d",&m);
	for(int i=2;i<=m;i++)
		alter(i);
	int sum=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(r[i][j]>=1) sum++;
	printf("%d\n",sum);
	return 0;
}