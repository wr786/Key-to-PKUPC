
#include<cstdio>
#include<map>
using namespace std;
int a[100001];
map<int,int> m;//判断是否重复
int main()
{
	//input
	int n;scanf("%d",&n);
	int idx=1;
	for(int i=1;i<=n;i++)
	{
		int temp;scanf("%d",&temp);
		if(m[temp]++) continue;
		a[idx++]=temp;
	}
	//output
	for(int i=1;i<idx;i++)
	{
		printf("%d",a[i]);
		if(i!=idx-1) printf(" ");
	}
	return 0;
}