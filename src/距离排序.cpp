#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,idx;
struct point {
	double x;
	double y;
	double z;
} p[11];

struct line {
	int p1;
	int p2;
	double dist;
} l[101];

int cmp(line A, line B) {
	if(A.dist == B.dist)
		if(A.p1 == B.p1)
			return A.p2 < B.p2;
		else
			return A.p1 < B.p1;
	else
		return A.dist > B.dist;
}

double POW2(double a, double b) {
	return (a-b)*(a-b);
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> p[i].x >> p[i].y >> p[i].z;
	}
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++) {
			l[++idx].dist = sqrt(POW2(p[i].x, p[j].x) + POW2(p[i].y, p[j].y) + POW2(p[i].z, p[j].z));
			l[idx].p1 = i;
			l[idx].p2 = j;
		}
	sort(l + 1, l + 1 + idx, cmp);
	for(int i = 1; i <= idx; i++) {
		printf("(%.0lf,%.0lf,%.0lf)-(%.0lf,%.0lf,%.0lf)=%.2lf\n", p[l[i].p1].x, p[l[i].p1].y, p[l[i].p1].z, p[l[i].p2].x, p[l[i].p2].y, p[l[i].p2].z, l[i].dist);
	}
	return 0;
}