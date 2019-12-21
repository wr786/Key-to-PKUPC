#include<cstdio>
int tree[10001];
int l[101],r[101];
int main()
{
	int L,m;scanf("%d%d",&L,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&l[i],&r[i]);
	//懒得排序，直接暴力
	for(int i=1;i<=m;i++)
		for(int j=l[i];j<=r[i];j++)
			tree[j]++;
	int cnt=0;
	for(int i=0;i<=L;i++)
		cnt+=(!tree[i]);
	printf("%d\n",cnt);
	return 0;
}