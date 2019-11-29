
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> a, b;

void READ() {
	int l1, l2; cin >> l1 >> l2;
	for(int i=0; i<l1; i++) {
		int tmp; cin >> tmp;
		a.push_back(tmp);
	}
	for(int i=0; i<l2; i++) {
		int tmp; cin >> tmp;
		b.push_back(tmp);
	}
}

void SORT() { // 懒得自分写
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
}

void MERGE() {
	for(int i=0; i<b.size(); i++)
		a.push_back(b[i]);
}

void DISPLAY() {
	for(int i=0; i<a.size(); i++) {
		if(i) cout << " ";
		cout << a[i];
	}
	cout << endl;
}

int main() {
	READ();SORT();MERGE();DISPLAY();
	return 0;
}
