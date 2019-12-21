#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	string str;int flag=0;//flag用来做标记
	getline(cin,str);
	for(int i=0;i<str.size();i++)
		if((int)str[i]%2==0)
		{
			if(flag++) printf(",");//如果不是第一次了就加个,
			printf("%d",(int)str[i]);		
		}
	if(!flag) printf("NO");//一次都没就NO
	printf("\n");return 0;
}