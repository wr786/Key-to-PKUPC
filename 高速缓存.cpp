// 这题其实题面有问题
// s实际上要换成s-1才能通过

#include<cstdio>
#include<algorithm>
using namespace std;
int m, s, E, n, counter, miss, rep;
struct data {
	int valid;
	int tag;
	int stamp;
} cache[260][17];

int main() {
	scanf("%d%d%d%d", &m, &s, &E, &n);
	int Addr;
	while (n--) {
		scanf("%d", &Addr);
		// 位运算取idx和tag	
		int idx = Addr & ((1<<3)-1);
		int tag = Addr & (int)((long long)(1<<m)-1); // 防爆范围
		int flag = 1;
		for(int i=1; i<=E; i++) {
			if (cache[idx][i].valid == 1 && cache[idx][i].tag == tag) {
				cache[idx][i].stamp = ++counter + miss + rep;
				flag = 0; break;
			}
		}
		if(flag) {
			// miss
			int flg = 1;
			for(int i=1; i<=E; i++)
				if(cache[idx][i].valid == 0) {
					flg = 0;
					cache[idx][i].stamp = counter + ++miss + rep;
					cache[idx][i].tag = tag;
					cache[idx][i].valid = 1;
				}
			if(flg) {
				int minidx = 1, minstamp = cache[idx][1].stamp;
				for(int i=2; i<=E; i++)
					if(cache[idx][i].stamp < minstamp) {
						minidx = i;
						minstamp = cache[idx][i].stamp;
					}
				cache[idx][minidx].tag = tag;
				cache[idx][minidx].stamp = couter + miss + ++rep;
			}
		}
	}
	printf("%d %d %d\n", counter, miss, rep);
	return 0;
}