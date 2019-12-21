include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string s, s1, s2;

int main() {
	cin >> s;
	int c1 = s.find(",");
	int c2 = s.find(",", c1+1);
	s1 = s.substr(c1+1 , c2-c1-1);
	s2 = s.substr(c2+1, s.length()-c2-1);
	s = s.substr(0, c1);
	int idx1 = s.find(s1), idx2 = s.find(s2);
	int l = s.length(), l1 = s1.length(), l2 = s2.length();
	if(idx1 >= l || idx2 >= l) cout << -1;
	else {
		int tmp = idx2;
		while(tmp <= l && tmp >= 0) {
			idx2 = tmp;
			tmp = s.find(s2, idx2+1);
		}
		if(idx2 - idx1 - l1 >= 0)	cout << idx2 - idx1 - l1;
		else cout << -1;
	}
	return 0;
}