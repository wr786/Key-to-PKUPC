#include<cstdio>
#define FOR(i,start,end) for(int i=start;i<=end;i++)
int n, a[101][101], preSum[101][101];
int main() {
  scanf("%d", &n);
  FOR(i,1,n) FOR(j,1,n) scanf("%d", &a[i][j]);
  FOR(i,1,n) FOR(j,1,n) preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] - preSum[i-1][j-1] + a[i][j];
  int maxNotEmptySubMtxVal = 0;
  FOR(X1,1,n) FOR(Y1,1,n) FOR(X2,X1,n) FOR(Y2,Y1,n) {
    int curSum = preSum[X2][Y2] - preSum[X2][Y1-1] - preSum[X1-1][Y2] + preSum[X1-1][Y1-1];
    if(curSum > maxNotEmptySubMtxVal) maxNotEmptySubMtxVal = curSum;
  }
  printf("%d\n", maxNotEmptySubMtxVal);
  return 0;
}