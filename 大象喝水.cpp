#include<cstdio>
#include "math.h"
#define PAI 3.14159
int main()
{
	double h,r;
	scanf("%lf%lf",&h,&r);
	printf("%d\n",(int)(ceil(20e3/(PAI*r*r*h))));
	return 0;
}