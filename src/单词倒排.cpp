#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string a[1001];
int idx;

int main() {
	string tmp;
	while(cin >> tmp) {
		a[++idx] = tmp;
	}
	for(int i=idx; i; i--) {
		if(i!=idx) cout<<" ";
		cout << a[i];
	}
	return 0;
}