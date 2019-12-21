#include<cstdio>

int main()
{
	float a;double b;
	scanf("%f%lf",&a,&b);
	printf("%f\n",a);
	printf("%.3lf\n",b);
	printf("%.5e\n",b);
	printf("%g\n",b);
	return 0;
}