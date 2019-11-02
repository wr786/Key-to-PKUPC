#include<cstdio>
#include<cmath>
int main()
{
	double x,a,e;scanf("%lf%lf%lf",&x,&a,&e);
	int i;
	for(i=1;;i++)
		if(x/(pow(a,i))<e&&x/(pow(a,i))>-e) break;
	printf("%d\n",i-1);//N要减一
	return 0;
}