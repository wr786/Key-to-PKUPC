#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n, a[501], cnt[151];

int main() {
	cin >> n;
	while(n--) {
		for(int i=0; i<=150; i++) cnt[i] = 0;
		string tmp; cin >> tmp;
		int l = tmp.length();
		int ret = 0, idx = 0;
		for(int i=0; i<l; i++) {
			if(tmp[i] == ',') {
				a[++idx] = ret;
				cnt[ret]++;
				ret = 0;
				continue;
			}
			ret = ret * 10 + tmp[i] - '0';
		}
		a[++idx] = ret; cnt[ret]++;
		int mode = a[1];
		for(int i=1; i<=idx; i++)
			if(cnt[a[i]] > cnt[mode]) mode = a[i];
		sort(a+1, a+1+idx);
		//输出众数
		cout << "mode=";
		if(cnt[mode] == idx) cout << "NO";
		else cout << mode;
		//输出中位数
		cout << ",median=";
		if(idx%2) { //奇数情况
			cout << a[idx/2+1];
		} else {
			cout << "(" << a[idx/2] << "+" << a[idx/2+1] <<")/2";
		}
		cout << endl;
	}
	return 0;
}