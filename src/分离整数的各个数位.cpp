#include<cstdio>
int main()
{
	int a;
	scanf("%d",&a);
	if(a<0) a=-a;//加绝对值
	printf("%d\n%d\n%d\n",a/100,(a/10)%10,a%10);//分离
	return 0;
}