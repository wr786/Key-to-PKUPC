#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int a[27];

int main() {
	int n; cin >> n;
	while(n--) {
		string tmp; cin >> tmp;
		int l = tmp.length();
		for(int i=0; i<=26; i++) a[i] = 0;
		for(int i=0; i<l; i++)
			a[tmp[i]-'a']++;
		int maxc = 0, maxn = 0;
		for(int i=0; i<=26; i++) {
			if(a[i] > maxn) {
				maxn = a[i];
				maxc = i;
			}
		}
		cout << (char)(maxc + 'a') << " " << maxn << endl;
	}
	return 0;
}