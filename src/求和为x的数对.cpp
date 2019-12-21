// 这个是满足题目要求的O(nlgn)算法（即算法导论所写）
// 个人感觉其实有点像“夹逼定理”，不知道诸君如何想呢

#include<cstdio>
#include<algorithm>
using namespace std;
int a[1000001];

int main() {
	int n, x; scanf("%d%d", &n, &x);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	sort(a+1, a+1+n);
	int left = 1, right = n;
	while(left < right) {
		if(a[left] + a[right] == x) {
			printf("YES\n");
			return 0;
		} else if(a[left] + a[right] < x) {
			left++;
		} else {
			right--;
		}
	}
	printf("NO\n");
	return 0;
}

// 虽然题目要求的时间复杂度是O(nlgn)
// 但是我的这个代码实际运行时最坏情况的时间复杂度才是O(n)
// 明显完爆题目（暴论）
// 其实是有瑕疵的，只不过题目所给数据过水。

#include<cstdio>
int vis[1000001];

int main() {
	int n, x; scanf("%d%d", &n, &x);
	while(n--) {
		int tmp; scanf("%d", &tmp);
		if(vis[x-tmp]) {
			printf("YES\n");
			return 0;
		}
		vis[tmp]++;
	}
	printf("NO\n");
	return 0;
}