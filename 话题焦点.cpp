#include<iostream>
#include<set>
using namespace std;
int beAt[101], n;
set<int> atOwner[101];

int main() {
	//读入微博
	cin >> n;
	while(n--) {
		int a, k; cin >> a >> k;
		for(int i = 1; i <= k; i++)
		{
			int ki; cin >> ki;
			beAt[ki]++;
			atOwner[ki].insert(a);
		}
	}
	//信息处理
	int atMax = beAt[1], atMaxId = 1;
	for(int i = 2; i <= 99; i++)
		if(beAt[i] > atMax) {
			atMax = beAt[i],
			atMaxId = i;
		}
	cout << atMaxId << endl;
	for(set<int>::iterator it = atOwner[atMaxId].begin(); it != atOwner[atMaxId].end(); ++it) {
		if(it != atOwner[atMaxId].begin()) cout << " ";
		cout << *it;
	}
	return 0;
	return 0;
}