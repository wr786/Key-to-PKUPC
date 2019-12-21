#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n,x,y;scanf("%d%d%d",&n,&x,&y);
	if(y%x) printf("%d\n",max(n-y/x-1,0));//多吃的
	else printf("%d\n",max(n-y/x,0));//必须>=0
	return 0;
}