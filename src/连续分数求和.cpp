#include<cstdio>
int main()
{
	int n;scanf("%d",&n);
	double S=0;
	for(int i=1;i<=n;i++)
		S+=1.0/(double)i;//求和
	printf("%.9lf\n",S);
	return 0;
}