#include<cstdio>
#include<algorithm>
using namespace std;
struct people{
	char c;int w;//名，重
} p[5];

int cmp(people A,people B)//比较函数
{
	return A.w>B.w;
}

int main()
{
	p[1].c='z';p[2].c='q';p[3].c='s';p[4].c='l';//initialize
	for(int z=1;z<=5;z++)
		for(int q=1;q<=5;q++)
			for(int s=1;s<=5;s++)
				for(int l=1;l<=5;l++)//暴力枚举
				{
					//题给条件
					if((z+q)!=(s+l)) continue;
					if(z+l<=s+q) continue;
					if(z+s>=q) continue;
					if(z==q&&q==s&&s==l) continue;
					p[1].w=z*10;p[2].w=q*10;p[3].w=s*10;p[4].w=l*10;
					break;//剪枝
				}
	sort(p+1,p+5,cmp);
	for(int i=1;i<=4;i++)
		printf("%c %d\n",p[i].c,p[i].w);
	return 0;
}