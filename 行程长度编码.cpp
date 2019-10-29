#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	string str; cin >> str;
	int l = str.length();
	if(str[0] >= 'a') str[0] = str[0] - 'a' + 'A';
	char NOW = str[0];
	int cnt = 1;
	for(int i=1; i<l; i++) {
		if(str[i] >= 'a') str[i] = str[i] - 'a' + 'A'; // upper
		if(NOW != str[i]) {
			printf("(%c,%d)", NOW, cnt);
			cnt = 0; // reset
			NOW = str[i];
		}
		cnt++;
	}
	printf("(%c,%d)", NOW, cnt);
	return 0;
}