
#include<iostream>
using namespace std;
int n, a[101][101], tmpn, flag, sum;

void remv() { // 划去11
	// DEBUG
	// for(int i=0; i<tmpn; i++){
	// 	for(int j=0; j<tmpn; j++)
	// 		cout << a[i][j];
	// 	cout << endl;
	// }
    // DEBUG
	sum += a[1][1];
	for(int j=1; j<tmpn-1; j++) // 消行
		for(int i=0; i<tmpn; i++)
			a[i][j] = a[i][j+1];
	for(int i=1; i<tmpn-1; i++)
		for(int j=0; j<tmpn; j++) // 消列
			a[i][j] = a[i+1][j];
	tmpn--;
	if(tmpn == 1){
		flag = 0;
		cout << sum << endl;
	}
}

int main() {
	cin >> n;
	for(int t=1; t<=n; t++) {
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				cin >> a[i][j];
		tmpn = n; flag = 1; sum = 0;// init	
		while(flag) {
			for(int i=0; i<tmpn; i++) { // 行减
				int minv = a[i][0];
				for(int j=1; j<tmpn; j++)
					if(a[i][j] < minv)
						minv = a[i][j];
				for(int j=0; j<tmpn; j++)
					a[i][j] -= minv;
			}
			for(int j=0; j<tmpn; j++) { // 列减
				int minv = a[0][j];
				for(int i=1; i<tmpn; i++)
					if(a[i][j] < minv)
						minv = a[i][j];
				for(int i=0; i<tmpn; i++)
					a[i][j] -= minv;
			}
			remv();
		}
	}
}

