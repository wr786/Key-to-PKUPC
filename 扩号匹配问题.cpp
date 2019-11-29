
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int brak[101];
string str;

int antifind(char c, int r) {
	int len = str.length();
	for(int i=r-1; i>=0; i--) {
		if(str[i] == c) return i;
	}
	return -1;
}

void matchbrak(int l ,int r) {
	if(l >= r) return;
	// cout << "[" << l << ":" << r << "]";
	int len = str.length();
	int p1 = antifind('(', r); // 找最右边的左括号
	int p2 = str.find(")", l);
	if(p1 < l || p1 >= r) { // 不存在左括号
		if(p2 < l || p2 >= r) { // 那没事了
			return;
		}
		// 不然则存在右括号
		while(p2 >= l &amp;&amp; p2 < r) { // 找出所有右括号打上标记
			brak[p2] = 2; // 代表右括号不匹配
			p2 = str.find(")", p2+1);
		}
		return;
	}
	// 不然则存在左括号
	if(p2 < l || p2 >= r) { // 不存在右括号
		while(p1 >= l &amp;&amp; p1 < r) {
			brak[p1] = 1; // 代表左括号不匹配
			p1 = antifind('(', p1);
		}
		return;
	}
	// 两者都存在
	int p1l = str.find("(", l);
	int p2r = antifind(')', r);
	while(p2 < p1l &amp;&amp; p2 >= l &amp;&amp; p2 < r) { // 括号逆序
		brak[p2] = 2;
		p2 = str.find(")", p2+1);
	}
	while(p1 > p2 &amp;&amp; p1 >= l &amp;&amp; p1 < r) {
		brak[p1] = 1;
		p1 = antifind('(', p1);
	}
	// if(p2 >= l &amp;&amp; p2 < r) {
	// 	while("寻找最右边的右括号") {
	// 		int tmp = str.find(")", p2+1);
	// 		if(tmp >= l &amp;&amp; tmp < r)
	// 			p2 = tmp;
	// 		else
	// 			break;
	// 	}
	// }
	if(p2 >= l &amp;&amp; p2 < r &amp;&amp; p1 >= l &amp;&amp; p1 < r) {
		// matchbrak(0, p1-1);
		// matchbrak(p1, p2);
		// matchbrak(p2+1, r);
		// 上面的方法会拆分外层括号
		str[p1] = str[p2] = ' ';
		matchbrak(l, r);
		brak[p1] = brak[p2] = 0;
	}
}

int main() {
	int n;
	for(cin >> n; n; n--) {
		cin >> str; cout << str << endl;
		int len = str.length();
		for(int i=0; i<len; i++) brak[i] = 0;
		matchbrak(0, len);
		for(int i=0; i<len; i++) {
			if(brak[i] == 0) cout << " ";
			else if(brak[i] == 1) cout << "$";
			else if(brak[i] == 2) cout << "?";
		}
		cout << endl;
	}
	return 0;
}
