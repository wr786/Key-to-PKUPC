#include<iostream>
#include<algorithm>
using namespace std;
// 射线法
struct point {
	int x;
	int y;
} p[101];


int main() {
	int x0, y0; cin >> x0 >> y0;
	int n; cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> p[i].x >> p[i].y;
	}
	int cnt_crosspoint = 0;
	for(int i=1; i<=n; i++) {
		int j = (i==n? 1: i+1);
		if(p[i].y == p[j].y) {
			if(p[i].y == y0) { // 在边上
				cnt_crosspoint = 0;
				break;
			}
			continue;
		}
		if(y0 > max(p[i].y, p[j].y)) continue;
		if(y0 <= min(p[i].y, p[j].y)) continue;
		int x1 = ((p[j].x - p[i].x) / (p[j].y - p[i].y)) * (y0 - p[i].y) + p[i].x;
		if(x1 > x0) cnt_crosspoint++;
		if(x1 == x0) { // 在边上
			cnt_crosspoint = 0;
			break;
		}
	}
	if(cnt_crosspoint % 2) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}