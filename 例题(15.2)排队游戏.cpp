
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;
stack<int> boys;
map<char, int> gender; // 2男，1女

int main() {
	string str; cin >> str;
	int len = str.length();
	int tmp = 2;
	for(int i=0; i<len; i++) {
		if(!gender[str[i]]) {
			gender[str[i]] = tmp;
			tmp--;
		}
		if(gender[str[i]] == 2) boys.push(i);
		else if(gender[str[i]] == 1) {
			cout << boys.top() << " " << i << endl;
			boys.pop();
		}
	}
	return 0;
}
