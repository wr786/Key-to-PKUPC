#include<cstdio>
#include<iostream>
using namespace std;
double sum;
int main()
{
	double n,W,H,A;cin>>n;
	char gender;
	while(n--)
	{
		cin>>gender>>W>>H>>A;
		if(gender=='F')
		{
			sum+=655+9.6*W+1.7*H-4.7*A;
		}
		else sum+=66+13.7*W+5.0*H-6.8*A;
	}
	printf("%.1lf\n",sum);
	return 0;
}