

// 分析：给出一个排列P，求出下一个排列P1是什么？
// 比如 P = 1 2 3 4 5。显然P1: 1 2 3 5 4。 P2：1 2 4 3 5。
// 规律： P->P1   :直接对 4 5 逆序。
//        P1->P2  : 后两个元素已经是逆序了，接下来就从后往前找出第一个正序的两个元素，也就是3 5，然后把3 和 4（逆序找第一个比3大的元素）交换，再把5（包括）之后的元素逆序。就可以得到下一个排列了。.
// 核心：逆序不可能存在下一个排列了，已经是最大了。

#include<cstdio>
#include<cstring>
int MAP[26], IDX;
int antiMAP[26];
int a[7], idx;
bool flag = true;

void reverse(int l, int r) {
	int b[7];
	for(int i=l; i<=r; i++) // 逆序存储工具数组
		b[r + l - i] = a[i];
	for(int i=l; i<=r; i++)
		a[i] = b[i]; // 反向赋值
}

void next_perm() {
	flag = false; // init
	int pos = 0;
	for(int i=idx; i>=2; i--) { // 逆序
		if(a[i-1] < a[i]) { // 找到了一对相邻正序对
			flag = true; // 并不是完全逆序，也就是说还有下一个排列
			for(int j=idx; j>=i; j--) { // 即j>i-1
				if(a[j] > a[i-1]) {
					//swap
					a[j] ^= a[i-1]; a[i-1] ^= a[j]; a[j] ^= a[i-1];
					pos = i;
					break;
				}
			}
			if(pos) break;
		}
	}
	// 将i之后的元素逆序
	reverse(pos, idx);
	if(flag) { // 如果有新的排列
		for(int i=1; i<=idx; i++) {
			printf("%c", antiMAP[a[i]]);
		}
		printf("\n");
	}
}

int main() {
	char C[7];
	scanf("%s", C);
	for(int i=0; i<strlen(C); i++) {
		char c = C[i];
		if(!MAP[c - 'a']) {
			MAP[c - 'a'] = ++IDX;
			antiMAP[IDX] = c;
		}
		a[++idx] = MAP[c - 'a'];
	}
	for(int i=1; i<=idx; i++) {
		printf("%c", antiMAP[a[i]]);
	} printf("\n");
	while(flag) next_perm();
	return 0;
}
