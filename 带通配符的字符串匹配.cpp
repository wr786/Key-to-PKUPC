
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string a, b;

bool fc(string a, string b) {
	int la = a.length(), lb = b.length();
    if(la > lb) {
        int tmpla = la;
        for(int i=0; i<la; i++)
            if(a[i] == '*') tmpla--;
        if(tmpla > lb) return false; // 特判过长
    }
	int idxa = 0, idxb = 0;
	while(idxa < la &amp;&amp; idxb < lb) {
		if(a[idxa] == '*') {
            if(idxa == la - 1) return true; // 特判最后一个
			for(int tmpidxb = idxb; tmpidxb < lb; tmpidxb++) {
				if(fc(a.substr(idxa + 1, la), b.substr(tmpidxb, lb))) {
                    return true;
                }
			}
            return false;
		} else if(a[idxa] == '?') {
			idxa++; idxb++;
		} else {
			if(a[idxa] != b[idxb]) return false;
			idxa++; idxb++;
		}
	}
    return a[la - 1] == '*'? 1 : (idxa == la); // 判断a是否也被匹配完
}

int main() {
	cin >> a >> b;
	if(fc(a, b)) cout << "matched\n";
	else cout << "not matched\n";
}