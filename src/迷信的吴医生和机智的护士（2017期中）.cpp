#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int n; cin >> n;
	int sum = 0;
	for(int i=1; n; i++) {
		if(i%4 == 0) continue;
		if(i%10 == 4 || i/10 == 4) continue;
		sum += i;
		n--;
	}
	cout << sum << endl;
}