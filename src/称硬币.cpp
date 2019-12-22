#include<iostream>
#include<string>
using namespace std;

int main() {
  int t; scanf("%d", &t);
  string leftStatement[3], rightStatement[3], op[3];
  while(t--) {
    for(int i=0; i<3; i++)
      cin >> leftStatement[i] >> rightStatement[i] >> op[i];
    bool solvedFlag = false; // to determine if is already solved
    for(int coin=0; coin<12 && !solvedFlag; coin++) // the fake coin
      for(int curWeight=0; curWeight<3 && !solvedFlag; curWeight+=2) { // it is light or heavy
        bool validFlag = true; // to determine if it is a valid solution
        for(int i=0; i<3; i++) {
          int leftLen = leftStatement[i].length(), rightLen = rightStatement[i].length();
          int leftSum = 0, rightSum = 0; // to calc the weightSum of the left and right
          for(int idx=0; idx<leftLen; idx++) {
            if(leftStatement[i][idx] - 'A' != coin) leftSum += 1; // normal weight is 1
            else leftSum += curWeight;
          }
          for(int idx=0; idx<rightLen; idx++) {
            if(rightStatement[i][idx] - 'A' != coin) rightSum += 1;
            else rightSum += curWeight;
          }
          if(op[i] == "even" && leftSum != rightSum) {validFlag = false; break;}
          else if(op[i] == "up" && leftSum <= rightSum) {validFlag = false; break;}
          else if(op[i] == "down" && leftSum >= rightSum) {validFlag = false; break;}
        }
        if(validFlag) {
          printf("%c is the counterfeit coin and it is %s.\n", coin + 'A', curWeight == 0? "light" : "heavy");
          solvedFlag = true;
          break;
        }
      }
  }
  return 0;
}
