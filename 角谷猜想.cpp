
#include<iostream>
using namespace std;

void recall(int n) {
	if(n == 1) {
		cout << "End\n";
		return;
	} else if(n % 2) { // odd
		int nxt = 3*n + 1;
		cout << n << "*3+1=" << nxt << endl;
		recall(nxt);
	} else {
		int nxt = n/2;
		cout << n << "/2=" << nxt << endl;
		recall(nxt);
	}
}

int main() {
	int n; cin >> n;
	recall(n);
}