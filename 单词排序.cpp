#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
string a[1001];
int idx;
map<string, int> vis;

int main() {
	string tmp;
	while(cin >> tmp) {
		if(vis[tmp]++) continue;
		a[++idx] = tmp;
	}
	//a[idx] = a[idx].substr(0,a[idx].length()-1);
	sort(a+1, a+1+idx);
	for(int i=1; i<=idx; i++)
		cout << a[i] << endl;
	return 0;
}