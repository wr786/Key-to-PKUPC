#include<iostream>
#include<algorithm>
using namespace std;
int a[6][6], M[6], m[6];

int main() {
	for(int i=1; i<=5; i++)
		for(int j=1; j<=5; j++)
			cin >> a[i][j];
	for(int i=1; i<=5; i++)
		for(int j=1; j<=5; j++) {
			if(a[i][j] > a[i][M[i]]) M[i] = j;
		}
	for(int i=1; i<=5; i++) a[0][i] = 9999999;
	for(int j=1; j<=5; j++)
		for(int i=1; i<=5; i++) {
			if(a[i][j] < a[m[j]][j]) m[j] = i;
		}
	for(int i=1; i<=5; i++)
		if(i == m[M[i]]) {
			cout << i << " " << M[i] << " " << a[i][M[i]];
			return 0;
		}
	cout << "not found\n";
	return 0;
}