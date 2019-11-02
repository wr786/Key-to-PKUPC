#include<cstdio>
#include<algorithm>
using namespace std;
int a[1001];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=n;i;i--)
	{
		printf("%d",a[i]);
		if(i>1) printf(" ");
	}
	return 0;
}