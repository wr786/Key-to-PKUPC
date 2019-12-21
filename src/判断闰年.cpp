#include<cstdio>
int main()
{
	int a;scanf("%d",&a);
	if(!(a%400))//四百年一闰
		printf("Y\n");
	else if(!(a%4)&&(a%100))//四年一闰，百年不闰
		printf("Y\n");
	else
		printf("N\n");
	return 0;
}