
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

struct braket {int l, r;};
bool cmp (braket A, braket B) {return B.r-B.l == A.r-A.l ? A.l<B.l : A.r-A.l < B.r-B.l;}
vector<braket> vec;

int main()
{
	string str; cin >> str;
	int len = str.length();
	stack<int> lefts;
	for(int i=0; i<len; i++) { // 处理字符串
		if(str[i] == '(') {
			lefts.push(i);
		} else if(str[i] == ')') {
			if(lefts.empty()) {
				cout << "mismatch\n";
				return 0;
			}
			int left =lefts.top(); lefts.pop();
			braket tmp; tmp.l = left+1, tmp.r = i+1; // 因为题面是从1开始的 
			vec.push_back(tmp);
		}
	}
	if(!lefts.empty()) { // 如果左括号过多
		cout << "mismatch\n";
		return 0;
	}
	if(vec.size()) { // 存在
		sort(vec.begin(), vec.end(), cmp);
		for(int i=0; i<vec.size(); i++) {
			cout << vec[i].l << "," << vec[i].r << endl;
		}
	} else { 
		cout << "0,0\n";
	}
	return 0;
}
