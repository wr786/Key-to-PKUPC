
#include<cstdio>

int main()
{
	double a,b;
	scanf("%lf%lf",&a,&b);
	printf("%g",a-b*(int)(a/b));//forced type conversion
	return 0;
}