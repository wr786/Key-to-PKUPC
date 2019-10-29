#include<iostream>
#include<algorithm>
using namespace std;
struct student {
	int id;
	double score;
} s[101];
int n, k;

int cmp(student A, student B) {
	return A.score > B.score;
}

int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> s[i].id >> s[i].score;
	sort(s + 1, s + 1 + n, cmp);
	cout << s[k].id << " " << s[k].score <<endl;
	return 0;
}