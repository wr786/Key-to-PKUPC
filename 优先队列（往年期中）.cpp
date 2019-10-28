#include<cstdio>
int heap[200001];
int n,m,tmp,Min=9999999,Max=0;
char op[21];

void read_in()
{
	scanf("%d",&tmp);
	heap[tmp]++;
	if(tmp>Max) Max=tmp;
	if(tmp<Min) Min=tmp;
}

int main()
{

	scanf("%d",&n);
	while(n--) read_in();
	scanf("%d",&m);
	while(m--)
	{
		scanf("%s",op);
		if(op[0]=='A')
			read_in();
		else
		{
			int flag=1;
			for(int i=Min;i<=Max;i++)
				if(heap[i])
				{
					printf("%d\n",i);
					heap[i]--;
					flag=0;
        			Min=i;
        			break;
				}
				if(flag) printf("NULL\n");
		}
	}
	return 0;
}