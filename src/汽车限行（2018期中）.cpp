#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	while(n--) {
		int y, m, d; scanf("%d-%d-%d", &y, &m, &d);
		string chepai; cin >> chepai;
		long long days = 0;
		// calculate the days before this year
		for(int i=2000; i<=y-1; i++) {
			for(int j=1; j<=12; j++) {
				switch(j) {
					case 1:
					case 3:
					case 5:
					case 7:
					case 8:
					case 10:
					case 12:
						days += 31;
						break;
					case 4:
					case 6:
					case 9:
					case 11:
						days += 30;
						break;
					case 2:
						if(i%4 == 0 && i%100 != 0)
							days += 29;
						else if(i%400 == 0)
							days += 29;
						else
							days +=28;
				}
			}
		}
		//this year before this month
		for(int j=1;j<=m-1;j++) {
			switch(j) {
					case 1:
					case 3:
					case 5:
					case 7:
					case 8:
					case 10:
					case 12:
						days += 31;
						break;
					case 4:
					case 6:
					case 9:
					case 11:
						days += 30;
						break;
					case 2:
						if(y%4 == 0 && y%100 != 0)
							days += 29;
						else if(y%400 == 0)
							days += 29;
						else
							days += 28;
						break;
			}
		}
		days += d;
		days--;
		int xingqi = (6 - 1 + days) % 7 + 1; 
		if(chepai[chepai.length()-1] == '1' || chepai[chepai.length()-1] == '6') {
			if(xingqi != 1) 
				cout << "no" << endl;
			else
				cout << "yes" << endl;
		} else if (chepai[chepai.length()-1] == '2' || chepai[chepai.length()-1] == '7') {
			if(xingqi != 2) 
				cout << "no" << endl;
			else
				cout << "yes" << endl;
		} else if (chepai[chepai.length()-1] == '3' || chepai[chepai.length()-1] == '8') {
			if(xingqi != 3) 
				cout << "no" << endl;
			else
				cout << "yes" << endl;
		} else if (chepai[chepai.length()-1] == '4' || chepai[chepai.length()-1] == '9') {
			if(xingqi != 4) 
				cout << "no" << endl;
			else
				cout << "yes" << endl;
		} else {
			if(xingqi != 5) 
				cout << "no" << endl;
			else
				cout << "yes" << endl;
		}
	}
	return 0;
}