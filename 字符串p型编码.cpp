
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	while(n--) {
		string str; cin >> str;
		int len = str.length();
		int combo = 1;
		char nowc = str[0];
		for(int i=1; i<len; i++) {
			if(nowc == str[i]) combo++;
			else {
				cout << combo << nowc;
				nowc = str[i];
				combo = 1;
			}
		}
		cout << combo << nowc << endl;
	}
}
