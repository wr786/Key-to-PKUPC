#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	string tmp;
	cin >> tmp;
	int l = tmp.length();
	int flag = 1;
	for(int i = 0; i <= (l-1)/2; i++) {
		if(tmp[i] != tmp[l-1-i]) {
			flag = 0;
			break;
		}
	}
	if(flag) cout << "yes";
	else cout << "no";
}