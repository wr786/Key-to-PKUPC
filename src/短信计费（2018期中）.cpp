#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	int n; cin >> n;
	int fee = 0;
	while(n--) {
		int text; cin >> text;
		fee += text / 70;
		if(text % 70) fee++;
	}
	printf("%.1lf", (double)fee/10);
	return 0;
} 