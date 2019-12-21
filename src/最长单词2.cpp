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
	a[idx] = a[idx].substr(0,a[idx].length()-1);
	string maxs = "";
	for(int i=1; i<=idx; i++)
		if(a[i].length() > maxs.length()) maxs = a[i];
	cout << maxs;
}