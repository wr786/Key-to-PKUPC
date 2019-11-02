#include<cstdio>
using namespace std;

int main()
{
	char c;
	scanf("%c",&c);
	((int)c%2)?printf("YES\n"):printf("NO\n");//forced type conversion
	return 0;
}