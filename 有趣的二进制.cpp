#include<iostream>
#include<cmath>
// n是二进制位数，a和b分别是两串二进制数，cnt代表所需交换次数
int n, a[205], b[205], cnt;
// diff存储a与b不同的位，a1代表该位a是1，b是0。idxa代表不同的位数
int diffa1[205], diffb1[205], idxa, idxb;

int main() {
	// 输入
	std::cin >> n;
	for(int i = 1; i <= n; i++)
		std::cin >> a[i];
	for(int i = 1; i <= n; i++)
		std::cin >> b[i];
	// 计算a和b发生不同的位
	for(int i = 1; i <= n; i++) {
		if(a[i] > b[i])
			diffa1[++idxa] = i;
		else if(b[i] > a[i])
			diffb1[++idxb] = i;
	}
	// 如果无解的话，输出-1
	if(idxa != idxb) {
		std::cout << -1 << std::endl;
		return 0;
	}
	// 分别排序不同的位，就近swap所需的次数是diffa1[i] - diffb1[i]。
	// 可以验证，不就近swap所需的swap次数一定>=就近swap的次数
	for(int i = 1; i <= idxa; i++)
		cnt += abs(diffa1[i] - diffb1[i]);
	std::cout << cnt << std::endl;
	return 0;
}