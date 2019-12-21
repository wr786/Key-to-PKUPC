#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n;cin>>n;
	int a=0,b=0,c=0,tmp;
	while(n--)
	{
		cin>>tmp;a+=tmp;
		cin>>tmp;b+=tmp;
		cin>>tmp;c+=tmp;
	}
	cout<<a<<" "<<b<<" "<<c<<" "<<a+b+c<<endl;
	return 0;
}