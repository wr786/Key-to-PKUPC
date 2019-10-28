#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[1001][1001],n,m;

int check()
{
	int flag=0;
	//shu
	for(int i=1;i<=n-4;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j]==1&&a[i+1][j]==1&&a[i+2][j]==1&&a[i+3][j]==1&&a[i+4][j]==1) flag=1;
			else if(a[i][j]==2&&a[i+1][j]==2&&a[i+2][j]==2&&a[i+3][j]==2&&a[i+4][j]==2) flag=2;
	if(flag) return flag;
	//heng
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n-4;j++)
			if(a[i][j]==1&&a[i][j+1]==1&&a[i][j+2]==1&&a[i][j+3]==1&&a[i][j+4]==1) flag=1;
			else if(a[i][j]==2&&a[i][j+1]==2&&a[i][j+2]==2&&a[i][j+3]==2&&a[i][j+4]==2) flag=2;
	if(flag) return flag;
	//youxia
	for(int i=1;i<=n-4;i++)
		for(int j=1;j<=n-4;j++)
			if(a[i][j]==1&&a[i+1][j+1]==1&&a[i+2][j+2]==1&&a[i+3][j+3]==1&&a[i+4][j+4]==1) flag=1;
			else if(a[i][j]==2&&a[i+1][j+1]==2&&a[i+2][j+2]==2&&a[i+3][j+3]==2&&a[i+4][j+4]==2) flag=2;
	if(flag) return flag;
	//zuoxia
	for(int i=1;i<=n-4;i++)
		for(int j=5;j<=n;j++)
			if(a[i][j]==1&&a[i+1][j-1]==1&&a[i+2][j-2]==1&&a[i+3][j-3]==1&&a[i+4][j-4]==1) flag=1;
			else if(a[i][j]==2&&a[i+1][j-1]==2&&a[i+2][j-2]==2&&a[i+3][j-3]==2&&a[i+4][j-4]==2) flag=2;
	if(flag) return flag;
	return 0;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;cin>>x>>y;
		if(i%2) a[x+1][y+1]=1;
		else a[x+1][y+1]=2;
		int flag=check();
		if(flag)
		{
			cout<<i<<" "<<flag-1<<endl;
			return 0;
		}
	}
	return 0;
}