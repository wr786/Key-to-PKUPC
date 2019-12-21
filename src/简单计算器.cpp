#include<cstdio>
int main()
{
	int a,b;char op;//两个数及操作符
	scanf("%d%d %c",&a,&b,&op);
	//分类讨论
	if(op=='+')
		printf("%d\n",a+b);
	else if(op=='-')
		printf("%d\n",a-b);
	else if(op=='*')
		printf("%d\n",a*b);
	else if(op=='/')
		if(b==0)
			printf("Divided by zero!\n");
		else
			printf("%d\n",a/b);
	else
		printf("Invalid operator!\n");
	return 0;
}