#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> vis;

int main() {
  string str, word; getline(cin, str); cin >> word;
  int len1 = str.length(), len2 = word.length();
  int curPos = str.find(word);
  int cnt = 0;
  while(curPos >= 0 && curPos < len1) {
    cnt++;
    curPos = str.find(word, curPos+1);
  }
  printf("%d\n", cnt);
  return 0;
}
