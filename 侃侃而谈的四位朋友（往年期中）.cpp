#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	for(int A=1;A<=15;A++)
		for(int B=1;B<=15;B++)
			for(int C=1;C<=15;C++)
				for(int D=1;D<=15;D++)
				{
					if((A&1)+(A&(2))/2+(A&(4))/4+(A&(8))/8!=2) continue;
					if((B&1)+(B&(2))/2+(B&(4))/4+(B&(8))/8!=2) continue;
					if((C&1)+(C&(2))/2+(C&(4))/4+(C&(8))/8!=2) continue;
					if((D&1)+(D&(2))/2+(D&(4))/4+(D&(8))/8!=1) continue;
					int flag=0;
					for(int i=1;i<=8;i<<=1)
					{
						if((A&i)/i+(B&i)/i+(C&i)/i+(D&i)/i==3) flag=1;
					}
					if(!flag) continue;
					if((A&8)==0) continue;
					if(D&8) continue;
					if(B&2) continue;
					if(A&C||C&D) continue;
					if((B&C)==0) continue;
					if(A&8&&A&4) continue;
					if(B&8&&B&4) continue;
					if(C&8&&C&4) continue;
					if(D&8&&D&4) continue;
					flag=0;
					for(int i=1;i<=8;i<<=1)
					{
						if(A&i)
						{
							if(flag) cout<<" ";
							if(i==1) cout<<1;
							if(i==2) cout<<2;
							if(i==4) cout<<3;
							if(i==8) cout<<4;
							flag++;
						}
					}
					cout<<endl;
					flag=0;
					for(int i=1;i<=8;i<<=1)
					{
						if(B&i)
						{
							if(flag) cout<<" ";
							if(i==1) cout<<1;
							if(i==2) cout<<2;
							if(i==4) cout<<3;
							if(i==8) cout<<4;
							flag++;
						}
					}
					cout<<endl;
					flag=0;
					for(int i=1;i<=8;i<<=1)
					{
						if(C&i)
						{
							if(flag) cout<<" ";
							if(i==1) cout<<1;
							if(i==2) cout<<2;
							if(i==4) cout<<3;
							if(i==8) cout<<4;
							flag++;
						}
					}
					cout<<endl;
					flag=0;
					for(int i=1;i<=8;i<<=1)
					{
						if(D&i)
						{
							if(flag) cout<<" ";
							if(i==1) cout<<1;
							if(i==2) cout<<2;
							if(i==4) cout<<3;
							if(i==8) cout<<4;
							flag++;
						}
					}
					cout<<endl;
					return 0;
				}
}