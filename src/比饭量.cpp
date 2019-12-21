#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	for(int a=1;a<=3;a++)
		for(int b=1;b<=3;b++)
			for(int c=1;c<=3;c++)//暴力枚举饭量
			{
				if(a==b||b==c||a==c) continue;//饭量不同,不然没有唯一解
				int fa=0,fb=0,fc=0;//正确个数
				if(b>a)fa++;if(a==c)fa++;//A
				if(a>b)fb++;if(a>c)fb++;//B
				if(c>b)fc++;if(b>a)fc++;//C
				if(fa==fb||fb==fc||fc==fa) continue;//同上。
				if(fa>fb&&a>b) continue;//反序
				if(fb>fc&&b>c) continue;//反序
				if(fc>fa&&c>a) continue;//反序
				if(fa>fc&&a>c) continue;//反序
				if(fb>fa&&b>a) continue;//反序
				if(fc>fb&&c>b) continue;//反序
				//升序输出
				int M=max(max(a,b),c),m=min(min(a,b),c);
				if(a==m) printf("A");
				else if(b==m) printf("B");
				else if(c==m) printf("C");
				if(a!=M&&a!=m) printf("A");
				else if(b!=M&&b!=m) printf("B");
				else if(c!=M&&c!=m) printf("C");
				if(a==M) printf("A");
				else if(b==M) printf("B");
				else if(c==M) printf("C");
				return 0;
			}
	return 0;
}