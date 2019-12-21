
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
map<string, int> Habb2Month;
map<int, string> Month2Tzolkin;

int main() {
	// init
	Habb2Month["pop"] = 1;
	Habb2Month["no"] = 2;
	Habb2Month["zip"] = 3;
	Habb2Month["zotz"] = 4;
	Habb2Month["tzec"] = 5;
	Habb2Month["xul"] = 6;
	Habb2Month["yoxkin"] = 7;
	Habb2Month["mol"] = 8;
	Habb2Month["chen"] = 9;
	Habb2Month["yax"] = 10;
	Habb2Month["zac"] = 11;
	Habb2Month["ceh"] = 12;
	Habb2Month["mac"] = 13;
	Habb2Month["kankin"] = 14;
	Habb2Month["muan"] = 15;
	Habb2Month["pax"] = 16;
	Habb2Month["koyab"] = 17;
	Habb2Month["cumhu"] = 18;
	Habb2Month["uayet"] = 19;
	Month2Tzolkin[1] = "imix";
	Month2Tzolkin[2] = "ik";
	Month2Tzolkin[3] = "akbal";
	Month2Tzolkin[4] = "kan";
	Month2Tzolkin[5] = "chicchan";
	Month2Tzolkin[6] = "cimi";
	Month2Tzolkin[7] = "manik";
	Month2Tzolkin[8] = "lamat";
	Month2Tzolkin[9] = "muluk";
	Month2Tzolkin[10] = "ok";
	Month2Tzolkin[11] = "chuen";
	Month2Tzolkin[12] = "eb";
	Month2Tzolkin[13] = "ben";
	Month2Tzolkin[14] = "ix";
	Month2Tzolkin[15] = "mem";
	Month2Tzolkin[16] = "cib";
	Month2Tzolkin[17] = "caban";
	Month2Tzolkin[18] = "eznab";
	Month2Tzolkin[19] = "canac";
	Month2Tzolkin[20] = "ahau";
	// 其中Tzolkin历法里数字范围是1~13
	// 字符串范围是1~20
	// 所以很自然想到取余
	int n; cin >> n; cout << n << endl;
	for(;n;n--) {
		int nichi, nenn;
		string getsu;
		cin >> nichi; scanf("."); // 去点
		cin >> getsu >> nenn;
		int month = Habb2Month[getsu];
		int days = nichi+1 + (month-1)*20 + nenn*365; // 不用考虑第19月，因为并非特殊情况
		int year = 0;
		while(days > 260) {
			year++;
			days -= 260;
		}
		if(days == 0) {
			cout << "1 imix " << year << endl;
			continue;
		}
		int datestrnum = (days-1)%20 + 1;
		string datestr = Month2Tzolkin[datestrnum];
		int datenum = (days-1)%13 + 1;
		cout << datenum << " " << datestr << " " << year << endl;
	}
}
