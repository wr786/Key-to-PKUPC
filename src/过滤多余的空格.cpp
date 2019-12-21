#include<iostream>
#include<string>
using namespace std;

int main()
{
	string tmp;
	int flag = 0;
	while(cin >> tmp) {
		if(flag) cout << " ";
		cout << tmp;
		flag++;
	}
	return 0;
}