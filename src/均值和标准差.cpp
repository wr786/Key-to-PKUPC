#include<cstdio>
#include "math.h"
int main()
{
	double a[101];
	int n;scanf("%d",&n);
	double sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&a[i]);
		sum+=a[i];
	}
	double ave=sum/n;printf("%.4lf ",ave);
	double sq=0;
	for(int i=1;i<=n;i++)
		sq+=(ave-a[i])*(ave-a[i]);
	printf("%.4lf\n",sqrt(sq/n));
	return 0;
}