// 对大数的进制转换，可以不用大数的除法运算。
// 假设要把一个二进制数1011，转换成一个三进制数。
// 1、用二进制数的第一位1去除以3，商为0，余数是1
// 2、由于前面一位的除法结果有余数，所以要把余数*(进制)+该为数字。对于本例，就是1(余数)*2(进制)+0(当前这位的数值)=2。除以3后，商0，余数是2
// 3、同2所述，2(余数)*2(进制)+1(当前这位的数值)=5。5除以3后，商1，余数2
// 4、同2所述，2(余数)*2(进制)+1(当前这位的数值)=5。5除以3后，商1，余数2
// 以上四步可以表示为 1011(2-based) / 3(要转换成的基数) = 0011(2-based 商).. 2(3-based 余数)
// 然后再让0011除以3，重复以上步骤，直到商为0。每次的余数的逆序就是以3为基的数。

// 1011/3 -->0011 ..2
// 0011/3 -->0001 ..0
// 0001/3 -->0000 ..1

// 所以，1011(2-based) --> 102(3-based)

#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int atoi_char(char c) {
	if(c <= '9') return c - '0';
	else return c - 'A' + 10;
}

char itoa_char(int num) {
	if(num < 10) return num + '0';
	else return num - 10 + 'A';
}

string alter(string str, int p, int q) { // 进制转换函数
	string ret = "", tmp = ""; // init
	while(str.length() != 0) { // 循环往复，直到商为0
		int rem = 0;
		for(int i=0; i<str.length(); i++) { // 除q取余法
			rem = rem * p + atoi_char(str[i]);
			tmp = tmp + itoa_char(rem / q);
			rem %= q;
		}
		ret = itoa_char(rem) + ret; // 倒序输出，甚至包括了输出为0的特例
		int idx = 0;
		while(tmp[0] == '0') tmp = tmp.substr(1, tmp.length()); // 去除前导零
		str = tmp;
		tmp = ""; // init
	}
	return ret;
}

int main() {
	int m; cin >> m;
	while(m--) {
		string str; cin >> str;
		int p1 = str.find(",");
		int p2 = str.find(",", p1+1);
		int p, q;
		if(p1 == 1) p = atoi_char(str[0]);
		else p = atoi_char(str[0]) * 10 + atoi_char(str[1]);
		if(p2 == str.length() - 2) q = atoi_char(str[str.length()-1]);
		else q = atoi_char(str[str.length()-2]) * 10 + atoi_char(str[str.length()-1]);
		// cout << itoa_plus(atoi_plus(str.substr(p1+1,p2-p1-1), p), q) << endl;
		cout << alter(str.substr(p1+1,p2-p1-1), p, q) << endl;
	}
	return 0;
}
