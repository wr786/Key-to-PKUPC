#include<iostream>
#include<string>
using namespace std;
// 自分实现atof
double my_atof(string str) {
	int l = str.length();
	double ret = 0.0;
	int sign = 1, digit = 0, flag=0;
	for(int i=0; i<l; i++) {
		if(flag) digit++;
		if(str[i] == '.') flag = 1;
		else if(str[i] == '-') sign = -1;
		else ret = ret * 10 + str[i] - '0';
	}
	while(digit--) ret *= 0.1;
	return sign * ret;
}

double PLUS(); double MINUS(); double TIMES(); double DIVIDE();

double operate(string op) {
	switch(op[0]) {
		case '+': return PLUS();
		case '-': return MINUS();
		case '*': return TIMES();
		case '/': return DIVIDE();
		default: return my_atof(op);
	}
}

double PLUS() {
	string a; cin >> a;
	double a1 = operate(a);
	string b; cin >> b;
	double b1= operate(b);
	return a1 + b1;
}

double MINUS() {
	string a; cin >> a;
	double a1 = operate(a);
	string b; cin >> b;
	double b1= operate(b);
	return a1 - b1;
}

double TIMES() {
	string a; cin >> a;
	double a1 = operate(a);
	string b; cin >> b;
	double b1= operate(b);
	return a1 * b1;
}

double DIVIDE() {
	string a; cin >> a;
	double a1 = operate(a);
	string b; cin >> b;
	double b1= operate(b);
	return a1 / b1;
}

int main() {
	double result = 0.0;
	string op; cin >> op;
	printf("%f\n", operate(op));
	return 0;
}
