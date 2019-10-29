#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int idx1 = s1.find(s2), idx2 = s2.find(s1);
	if(idx1 <= s1.length() && idx1 >=0) {
		cout << s2 << " is substring of " << s1;
	} else if(idx2 <= s2.length() && idx2 >= 0) {
		cout << s1 << " is substring of " << s2;
	} else {
		cout << "No substring\n";
	}
	return 0;
}