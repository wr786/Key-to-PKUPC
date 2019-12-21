#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int y, m, d; cin >> y >> m >> d;
	int days = 0;
	// calculate the days before this year
	for(int i=1990; i<=y-1; i++) {
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
					if(i%4 == 0 && i%100 !=0)
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
					if(y%4 == 0 && y%100 !=0)
						days += 29;
					else if(y%400 == 0)
						days += 29;
					else
						days +=28;
		}
	}
	days += d;
	days--;
	int situation = days % 5;
	if(situation < 3) cout<<"fishing"<<endl;
	else cout<<"sleeping"<<endl;
	return 0;
}