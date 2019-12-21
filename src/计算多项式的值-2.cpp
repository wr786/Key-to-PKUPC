#include<cstdio>
#include "math.h"

int main()
{
	double x;int n;
	scanf("%lf%d",&x,&n);
	//通过等比数列求和可以知道多项式其实就是(x^(n+1)-1)/(x-1)
	if(x==1.0)
		printf("%d.00",n+1);//特别判别x=1的情况
	else
		printf("%.2lf\n",(pow(x,n+1)-1)/(x-1));
	return 0;
}