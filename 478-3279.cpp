#include<iostream>
#include<string>
#include<map>
using namespace std;
map<char, int> m;

int main() {
	//预处理
	m['A'] = m['B'] = m['C'] = 2;
	m['D'] = m['E'] = m['F'] = 3;
	m['G'] = m['H'] = m['I'] = 4;
	m['J'] = m['K'] = m['L'] = 5;
	m['M'] = m['N'] = m['O'] = 6;
	m['P'] = m['Q'] = m['S'] = 7;
	m['T'] = m['U'] = m['V'] = 8;
	m['W'] = m['X'] = m['Y'] = 9;
	//处理
	int n; cin >> n;
	while(n--) {
		string tmp; cin >> tmp;
		int l = tmp.length();
		int cnt = 0;
		for(int i = 0; i < l; i++) {
			if(tmp[i] == '-') continue;
			if(++cnt == 4) cout << '-';
			if(tmp[i] >= 'A') cout << m[tmp[i]];
			else cout << tmp[i];
		}
		cout << endl;
	}
	return 0;
}