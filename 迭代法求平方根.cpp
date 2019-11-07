#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
double a, res;

void f(double n) {
	double n_1 = 0.5 * (n + a/n);
	if(abs(n_1 - n) <= 1e-5) {
		res = n_1;
		return;
	}
	f(n_1);
}

int main() {
	cin >> a;
	f(1);
	printf("%.7lf", res);
	return 0;
}
