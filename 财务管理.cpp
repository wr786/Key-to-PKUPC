#include<cstdio>
int main()
{
	double sum=0;//求和
	for(int i=1;i<=12;i++)
	{
		double tmp;scanf("%lf",&tmp);
		sum+=tmp;
	}
	printf("$%.2lf\n",sum/12.0);//平均
	return 0;
}