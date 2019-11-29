
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	while(n--) {
		string str;
		scanf("\n"); // 去换行符
		getline(cin ,str);
		// 字符串分拆
		int separ = str.find(":");
		string a = str.substr(0, separ);
		string b = str.substr(separ + 1, str.length());
		int idx = 0; bool flag = false;
		int la = a.length(), lb = b.length();
		if(la >= lb) { // 判断是否缩略
			cout << "NO" << endl;
			continue;
		}
		for(int i=0; i<la; i++) {
			int pos = b.find(str[i], idx);
			if(pos < 0 || pos >= lb) {
				cout << "NO" << endl;
				flag = true;
				break;
			}
			idx = pos + 1;
		}
		if(flag) continue;
		cout << "YES" << endl;
	}
	return 0;
}
