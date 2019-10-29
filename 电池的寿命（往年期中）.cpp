#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
double a[1001];
int n;

int main()
{
	while(cin>>n)
	{
		double sum=0,mini=99999999,maxi=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			sum+=a[i];
			mini=min(a[i],mini);
            maxi=max(a[i],maxi);
		}
		if(n==2) printf("%.1lf\n",mini);
		else if(maxi>sum/2) printf("%.1lf\n",sum-maxi); 
        else printf("%.1lf\n",sum/2);
	}
	return 0;
}