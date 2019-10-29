#include<iostream>
#include<algorithm>
using namespace std;
int a[101][101], n;

int main() {
	while(cin >> n) {
		if(!n) break;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				cin >> a[i][j];
		int row = 0, col = 0, flag = 0;
		for(int i = 1; i <= n; i++) {
			int tmp = 0;
			for(int j = 1; j <= n; j++) {
				tmp = (tmp + a[i][j]) % 2;
			}
			if(tmp)
				if(row) flag++;
				else row = i;
		}
		for(int j = 1; j <= n; j++) {
			int tmp = 0;
			for(int i = 1; i <= n; i++) {
				tmp = (tmp + a[i][j]) % 2;
			}
			if(tmp)
				if(col) flag++;
				else col = j;
		}
		if(flag) cout << "Corrupt\n";
		else if(row && col) cout << "Change bit (" << row << "," << col << ")\n";
		else cout << "OK\n";
	}
	return 0;
}