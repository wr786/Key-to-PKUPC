#include<cstdio>
#include<algorithm>
using namespace std;
int a[21],f[10001];//分别存要的数据和斐波那契数列
int main()
{
	int n;scanf("%d",&n);
	int m=0;//记录最大数
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		m=max(m,a[i]);
	}
	f[1]=1;f[2]=1;
	for(int i=3;i<=m;i++)
		f[i]=f[i-1]+f[i-2];//暴力递推
	for(int i=1;i<=n;i++)
		printf("%d\n",f[a[i]]);//输出
	return 0;
}