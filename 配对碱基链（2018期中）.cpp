#include<iostream>
#include<string>
using namespace std;

int main() {
	int n; cin >> n;
	while(n--) {
		string tmp; cin >> tmp;
		int l = tmp.length();
		for(int i=0; i<l; i++) {
			if(tmp[i] == 'A')
				cout << 'T';
			if(tmp[i] == 'T')
				cout << 'A';
			if(tmp[i] == 'C')
				cout << 'G';
			if(tmp[i] == 'G')
				cout << 'C';
		}
		cout << endl;
	}
	return 0;
}