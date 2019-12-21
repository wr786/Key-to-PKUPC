#include<cstdio>
int main()
{
	double h;scanf("%lf",&h);
	double sum=h;
	for(int i=1;i<=10;i++)//10次
	{
		h/=2;//减半
		if(i<10) sum+=2*h;
	}
	printf("%g\n%.6lf\n",sum,h);
	return 0;
}