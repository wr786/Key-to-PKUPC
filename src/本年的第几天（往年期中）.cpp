#include<cstdio>
#include<iostream>
using namespace std;
int p[13];
int main()
{
	int y,m,d;cin>>y>>m>>d;
	p[2]=31;
	if((y%4==0&&y%100)||y%400==0) p[3]=29+p[2];
	else p[3]=28+p[2];
	p[4]=31+p[3];
	p[5]=30+p[4];
	p[6]=31+p[5];
	p[7]=30+p[6];
	p[8]=31+p[7];
	p[9]=31+p[8];
	p[10]=30+p[9];
	p[11]=31+p[10];
	p[12]=30+p[11];
	cout<<p[m]+d<<endl;
	return 0;
}