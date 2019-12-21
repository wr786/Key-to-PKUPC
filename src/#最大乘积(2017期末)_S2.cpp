#include<cstdio>
inline int read() {
  int ret = 0, sign = 1;
  int c = getchar();
  while(c == ' ' || c == '\n') c = getchar();
  if(c == '-') {
    sign = -1;
    c = getchar();
  }
  while('0' <= c && c <= '9') {
    ret = ret*10 + c - '0';
    c = getchar();
  }
  return sign * ret;
}
int ans[1001], idx;

int main() {
	int s = read();
  if(s <= 4) {
    printf("%d\n", s);
    return 0;
  }
  int sum = 0;
  // 贪心，从2开始累加
	for(int i=2; i<=s; i++) {
    sum += i;
    ans[++idx] = i;
    if(sum > s) break;
	}
  // 如果只比结果多1，那么减去2，并使最后一个数加1即可。
  if(sum - s == 1) {
    for(int i=2; i<idx; i++) {
      printf("%d ", ans[i]);
    } printf("%d\n", ans[idx]+1);
    return 0;
  }
  // 如果比结果多x>1，则删去x即可
  int flag = 0;
  for(int i=1; i<=idx; i++) {
    if(ans[i] != sum - s) {
      if(flag++) printf(" ");
      printf("%d", ans[i]);
    }
  }
  return 0;
}
