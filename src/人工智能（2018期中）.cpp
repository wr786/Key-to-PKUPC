#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
double U, I, P;

int main() {
	int n, flag; cin >> n;
	scanf("\n");
	for(int k=1; k<=n; k++) {
		string tmp; getline(cin, tmp);
		//scanf("\n");
		int u = tmp.find("U=");
		int i = tmp.find("I=");
		int p = tmp.find("P=");
		if(u >= tmp.length() || u < 0) { // given I,P
			I = 0, flag = 1;
			double I2 = 0; int weishu = 0;
			for(int _i = i + 2;;_i++) {
				if(tmp[_i] == 'A') {
					while(weishu--) I2 *= 0.1;
					I = I + I2;
					break;
				}
				if(tmp[_i] == 'm') {
					while(weishu--) I2 *= 0.1;
					I = I + I2;
					I = I * 1e-3;
					break;
				}
				if(tmp[_i] == 'k') {
					while(weishu--) I2 *= 0.1;
					I = I + I2;
					I = I * 1e3;
					break;
				}
				if(tmp[_i] == 'M') {
					while(weishu--) I2 *= 0.1;
					I = I + I2;
					I = I * 1e6;
					break;
				}
				if(tmp[_i] == '.') {
					flag = 0;
					continue;
				}
				if(flag) {
					I = I * 10 + tmp[_i] - '0';
				} else {
					I2 = I2 * 10 + tmp[_i] - '0';	
					weishu++;
				}
			}
			P = 0, flag = 1;
			double P2 = 0; weishu = 0;
			for(int _i = p + 2;;_i++) {
				if(tmp[_i] == 'W') {
					while(weishu--) P2 *= 0.1;
					P = P + P2;
					break;
				}
				if(tmp[_i] == 'm') {
					while(weishu--) P2 *= 0.1;
					P = P + P2;
					P = P * 1e-3;
					break;
				}
				if(tmp[_i] == 'k') {
					while(weishu--) P2 *= 0.1;
					P = P + P2;
					P = P * 1e3;
					break;
				}
				if(tmp[_i] == 'M') {
					while(weishu--) P2 *= 0.1;
					P = P + P2;
					P = P * 1e6;
					break;
				}
				if(tmp[_i] == '.') {
					flag = 0;
					continue;
				}
				if(flag) {
					P = P * 10 + tmp[_i] - '0';
				} else {
					P2 = P2 * 10 + tmp[_i] - '0';	
					weishu++;
				}
			}
			cout << "Problem #" << k << endl;
			printf("U=%.2lfV\n\n", P/I);
		}
		else if(i >= tmp.length() || i < 0) { // given U,P
			U = 0, flag = 1;
			double U2 = 0; int weishu = 0;
			for(int _i = u + 2;;_i++) {
				if(tmp[_i] == 'V') {
					while(weishu--) U2 *= 0.1;
					U = U + U2;
					break;
				}
				if(tmp[_i] == 'm') {
					while(weishu--) U2 *= 0.1;
					U = U + U2;
					U = U * 1e-3;
					break;
				}
				if(tmp[_i] == 'k') {
					while(weishu--) U2 *= 0.1;
					U = U + U2;
					U = U * 1e3;
					break;
				}
				if(tmp[_i] == 'M') {
					while(weishu--) U2 *= 0.1;
					U = U + U2;
					U = U * 1e6;
					break;
				}
				if(tmp[_i] == '.') {
					flag = 0;
					continue;
				}
				if(flag) {
					U = U * 10 + tmp[_i] - '0';
				} else {
					U2 = U2 * 10 + tmp[_i] - '0';	
					weishu++;
				}
			}
			P = 0, flag = 1;
			double P2 = 0; weishu = 0;
			for(int _i = p + 2;;_i++) {
				if(tmp[_i] == 'W') {
					while(weishu--) P2 *= 0.1;
					P = P + P2;
					break;
				}
				if(tmp[_i] == 'm') {
					while(weishu--) P2 *= 0.1;
					P = P + P2;
					P = P * 1e-3;
					break;
				}
				if(tmp[_i] == 'k') {
					while(weishu--) P2 *= 0.1;
					P = P + P2;
					P = P * 1e3;
					break;
				}
				if(tmp[_i] == 'M') {
					while(weishu--) P2 *= 0.1;
					P = P + P2;
					P = P * 1e6;
					break;
				}
				if(tmp[_i] == '.') {
					flag = 0;
					continue;
				}
				if(flag) {
					P = P * 10 + tmp[_i] - '0';
				} else {
					P2 = P2 * 10 + tmp[_i] - '0';	
					weishu++;
				}
			}
			cout << "Problem #" << k << endl;
			printf("I=%.2lfA\n\n", P/U);
		}
		else if(p >= tmp.length() || p < 0) { // given U,I
			U = 0, flag = 1;
			double U2 = 0; int weishu = 0;
			for(int _i = u + 2;;_i++) {
				if(tmp[_i] == 'V') {
					while(weishu--) U2 *= 0.1;
					U = U + U2;
					break;
				}
				if(tmp[_i] == 'm') {
					while(weishu--) U2 *= 0.1;
					U = U + U2;
					U = U * 1e-3;
					break;
				}
				if(tmp[_i] == 'k') {
					while(weishu--) U2 *= 0.1;
					U = U + U2;
					U = U * 1e3;
					break;
				}
				if(tmp[_i] == 'M') {
					while(weishu--) U2 *= 0.1;
					U = U + U2;
					U = U * 1e6;
					break;
				}
				if(tmp[_i] == '.') {
					flag = 0;
					continue;
				}
				if(flag) {
					U = U * 10 + tmp[_i] - '0';
				} else {
					U2 = U2 * 10 + tmp[_i] - '0';	
					weishu++;
				}
			}
			I = 0, flag = 1;
			double I2 = 0; weishu = 0;
			for(int _i = i + 2;;_i++) {
				if(tmp[_i] == 'A') {
					while(weishu--) I2 *= 0.1;
					I = I + I2;
					break;
				}
				if(tmp[_i] == 'm') {
					while(weishu--) I2 *= 0.1;
					I = I + I2;
					I = I * 1e-3;
					break;
				}
				if(tmp[_i] == 'k') {
					while(weishu--) I2 *= 0.1;
					I = I + I2;
					I = I * 1e3;
					break;
				}
				if(tmp[_i] == 'M') {
					while(weishu--) I2 *= 0.1;
					I = I + I2;
					I = I * 1e6;
					break;
				}
				if(tmp[_i] == '.') {
					flag = 0;
					continue;
				}
				if(flag) {
					I = I * 10 + tmp[_i] - '0';
				} else {
					I2 = I2 * 10 + tmp[_i] - '0';	
					weishu++;
				}
			}
			cout << "Problem #" << k << endl;
			printf("P=%.2lfW\n\n", U*I);
		}
	}
	return 0;
}