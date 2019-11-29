
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int search(int turn_player, long long a, long long b) {
	if(a == 0 || b == 0) return 3 - turn_player; // 判断是否有取完一堆石子
	if(a < b) a ^= b, b ^= a, a ^= b; // swap
	if((a/b) >= 2) return turn_player; // 此时有先手策略者必胜
	else { // 此时 b < a < 2b , 只有一种取法
		return search(3 - turn_player, a - b, b);
	}
}

int main() {
	long long a, b;
	cin >> a >> b;
	while(a &amp;&amp; b) {
		if(search(1, a, b) == 1)
			cout << "win" << endl;
		else
			cout << "lose" << endl;
		cin >> a >> b;
	}
	return 0;
}
