#include<cstdio>
#include<algorithm>
using namespace std;
struct pym{
	int idx;
	double rate;
} p[101];

int cmp(pym A,pym B)
{
	return A.rate<B.rate;
}

int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		double b,e;
		scanf("%d%lf%lf",&p[i].idx,&b,&e);
		p[i].rate=e/b;
	}
	sort(p+1,p+1+n,cmp);
	double mdiff=0;int midx=0;//记录分界点
	for(int i=1;i<=n-1;i++)
	{
		if(p[i+1].rate-p[i].rate>mdiff)
			mdiff=p[i+1].rate-p[i].rate,midx=i;
	}
	printf("%d\n",n-midx);
	for(int i=midx+1;i<=n;i++)//A
		printf("%d\n",p[i].idx);
	printf("%d\n",midx);
	for(int i=1;i<=midx;i++)//B
		printf("%d\n",p[i].idx);
	return 0;
}