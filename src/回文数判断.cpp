
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

int main() {
	string str;
	cin >> str;
	int len = str.length();
	bool flag = true;
	for(int i=0; i<len/2; i++) {
		if(str[i] != str[len-1 - i]) {
			flag = false;
			break;
		}
	}
	if(flag) cout << "yes";
	else cout << "no";
}