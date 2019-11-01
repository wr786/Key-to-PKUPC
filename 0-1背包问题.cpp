// 这题虽然从题名来看很像某个经典的DP背包问题
// 但是实际上这里是实数啊！用DP非常不好写
// 所以不如直接就用搜索来实现了
// 值得注意的是，如果不排序的话，可能会超时一点点
// 顺带一提我代码的效率：最耗时点800ms

#include<cstdio>
#include<algorithm>
int n;
double m;

struct shina_mono {
	double weight;
	double value;
} mono[10001];

bool cmp(shina_mono A, shina_mono B) {return A.weight < B.weight;}

double search(int pos, double space_left, double value_sum) {
	if(pos > n) return value_sum;
	if(mono[pos].weight > space_left) return value_sum;
	return std::max(search(pos + 1, space_left, value_sum), search(pos + 1, space_left - mono[pos].weight, value_sum + mono[pos].value));
}

int main() {
	scanf("%d%lf", &n, &m);
	for (int i=1; i<=n; i++)
		scanf("%lf%lf", &mono[i].weight, &mono[i].value);
	std::sort(mono + 1, mono + 1 + n, cmp);
	double ans = search(1, m, 0);
	printf("%.5lf\n", ans);
	return 0;
}
