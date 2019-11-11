#include<iostream>
#include<string>
using namespace std;
string str[10001], maxstr, minstr="666";
int idx, minlength = 786554453, maxlength = 0;


void maintain(string s) {
  if(s == "") return;
	int len = s.length();
	if(len > maxlength) {
		maxlength = len;
		maxstr = s;
	}
	if(len < minlength) {
		minlength = len;
		minstr = s;
	}
}

int main() {
	while(cin >> str[++idx]);
	if(str[idx][str[idx].length()-1] == '.')
		str[idx] = str[idx].substr(0, str[idx].length()-1);
	for(int i=1; i<=idx; i++) {
		int pos = str[i].find(",");
	    int l = str[i].length();
	    if(pos >= 0 && pos < l) {
	      string s1 = str[i].substr(0,pos);
	      string s2 = str[i].substr(pos+1,l-pos);
	      maintain(s1); maintain(s2);
	    } else {
	    	maintain(str[i]);
	    }
	}
  cout << maxstr << endl << minstr << endl;
  return 0;
}
