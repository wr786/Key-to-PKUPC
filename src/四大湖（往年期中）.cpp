#include<cstdio>
int main()
{
	for(int b=1;b<=4;b++)
		for(int d=1;d<=4;d++)
		{
			if(b==d) continue;
			for(int t=1;t<=4;t++)
			{
				if(b==t||d==t) continue;
				for(int h=1;h<=4;h++)
				{
					if(b==h||t==h||d==h) continue;
					int A=(d==4)+(h==1)+(b==2);
					int B=(h==4)+(d==1)+(b==3)+(t==2);
					int C=(h==1)+(d==2);
					int D=(b==4)+(t==1)+(h==3)+(d==2);
					if(A!=1||B!=1||C!=1||D!=1) continue;
					printf("%d\n%d\n%d\n%d\n",5-b,5-d,5-t,5-h);
					return 0;
				}
			}
		}
}