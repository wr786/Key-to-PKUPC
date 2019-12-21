#include<cstdio>
int main()
{
	int y,m,d;scanf("%d-%d-%d",&y,&m,&d);
	if(m!=2)
	{
		if(d<30) printf("%d-%02d-%02d\n",y,m,d+1);
		else
		{
			if(d==30&&(m==1||m==3||m==5||m==7||m==8||m==10||m==12))
				printf("%d-%02d-%02d\n",y,m,d+1);
			else if(d==30&&!(m==1||m==3||m==5||m==7||m==8||m==10||m==12))
				printf("%d-%02d-%02d\n",y,m+1,1);
			else if(d==31&&m==12)
				printf("%d-%02d-%02d\n",y+1,1,1);
			else
				printf("%d-%02d-%02d\n",y,m+1,1);
		}

	}
	else
	{
		if(d<28) printf("%d-%02d-%02d\n",y,m,d+1);
		else if(d==29) printf("%d-%02d-%02d\n",y,m+1,1);
		else
		{
			bool isrun=0;
			if(!(y%4)&&(y%100)) isrun=1;
			if(!(y%400)) isrun=1;
			if(isrun) printf("%d-%02d-%02d\n",y,m,d+1);
			else printf("%d-%02d-%02d\n",y,m+1,1);
		}
	}
	return 0;
}