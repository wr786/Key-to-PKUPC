#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
string myEmailAddr;
struct myCilent {
	string userName;
	string password;
	string email;
} mc[10001];
int idx;

int main() {
	cin >> myEmailAddr;
	int accountNum; cin >> accountNum;
	for(int i=1; i<=accountNum; i++) {
		string usr, psw, eml;
		cin >> usr >> psw >> eml;
		if(eml != myEmailAddr) continue;
		mc[++idx].userName = usr;
		mc[idx].password = psw;
		mc[idx].email = eml;
	}
	if(!idx) cout << "empty\n";
	else {
		for(int i=1; i<=idx; i++) {
			cout << mc[i].userName;
			string psw = mc[i].password;
			int l = psw.length();
			for(int i=0; i<l; i++) { // 大小写互换
				if(psw[i] >= 'a' && psw[i] <= 'z') psw[i] = psw[i] - 'a' + 'A';
				else if(psw[i] <= 'Z' && psw[i] >= 'A') psw[i] = psw[i] - 'A' + 'a';
			}
			cout << " " << psw <<endl;
		}
	}
	return 0;
}