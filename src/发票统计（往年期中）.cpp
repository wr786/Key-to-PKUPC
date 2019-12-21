#include<cstdio>
double a[4],A,B,C;
int main()
{
	for(int i=1;i<=3;i++)
	{
		int n;
		scanf("%d",&n);
		scanf("%d",&n);
		for(int j=1;j<=n;j++)
		{
			char type;scanf(" %c",&type);
			double tmp;scanf("%lf",&tmp);
			if(type=='A') A+=tmp;
			if(type=='B') B+=tmp;
			if(type=='C') C+=tmp;
			a[i]+=tmp;
		}
		printf("%d %.2lf\n",i,a[i]);
	}
	printf("A %.2lf\n",A);
	printf("B %.2lf\n",B);
	printf("C %.2lf\n",C);
	return 0;
}