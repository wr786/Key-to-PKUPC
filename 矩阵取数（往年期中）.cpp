#include<cstdio>
#include<algorithm>
using namespace std;
int d[82][82][82],a[82][82],n,m;

int main()
{
	scanf("%d%d",&n,&m);
	//输入
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	//动态规划
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
			for(int r=m;r>=l;r--)
			{
				int cnt=m-(r-l)-1;
				d[i][l][r]=max(d[i][l][r+1]+a[i][r+1]*cnt,d[i][l-1][r]+a[i][l-1]*cnt); //状态转移
			}
	//输出
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		int maxd=0;
		for(int j=1;j<=m;j++)
			maxd=max(maxd,d[i][j][j]+a[i][j]*m); //加上最后一次
		sum+=maxd;
	}
	printf("%d\n",sum);
	return 0;
}