#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int x, y, xi; cin >> x >> y;
	while(x && y) {
		if(y > x) swap(x, y);
		if(x == y) {
			xi = x;
			break;
		}
		// x > y
		x = x / 2; // 使x变成怹的祖先
	}
	cout << xi << endl;
	return 0;
}
