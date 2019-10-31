#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int n; cin >> n;
	if(n == 1 || n == 3 || n == 5)
		cout << "NO";
	else
		cout << "YES";
	return 0; 
}