#include<cstdio>
#include<cmath>

int main()
{
	int n;double a,b,c;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lf%lf%lf",&a,&b,&c);
		double delta=b*b-4*a*c;//判别式
		double ret1=-b/(2*a)+0.0;
		if(delta==0)
			printf("x1=x2=%.5lf\n",ret1);
		else if(delta>0)
		{
			double ret2=sqrt(delta)/(2*a);
			printf("x1=%.5lf;x2=%.5lf\n",ret1+ret2,ret1-ret2);
		}
		else
		{
			double ret2=sqrt(-delta)/(2*a);
			printf("x1=%.5lf+%.5lfi;x2=%.5lf-%.5lfi\n",ret1,ret2,ret1,ret2);
		}
	}
	return 0;
}