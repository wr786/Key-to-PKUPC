
// std header

// C
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

vector<int> frc;

void srch(int n)
{
	// 以n=15为例
	int sum = 0;
	// 第一步，因为要取不同的数，从小到大遍历数使和为n，除了最后一个数以外间隔为1
	for (int i = 2;; ++i)
	{
		sum += i;
		frc.push_back(i);
		if (sum == n)
			break;
		if (sum > n)
		{
			sum -= i;
			sum -= i - 1;
			frc.pop_back();
			frc.pop_back();
			--i;
		}
	}
	// 此时得到了2,3,4,6
	// 第二步，最后一个数和倒数第二个的差值diff
	int diff = frc.back() - frc[frc.size() - 2] - 1;
	// 尽可能把diff分给前面的数
	// 如果diff比较大，则可以给前面的数每个多1（从选数方式可以知道不可能可以给更多）
	if ((int)frc.size() - diff < 0)
		for (int i = 0; i < frc.size() - 1; ++i)
		{
			++frc[i];
			--frc.back();
		}
	// 如果diff比较小，则只能给靠后面的数每个多1
	else
		for (int i = 0; i < diff; ++i)
		{
			++frc[frc.size() - 1 - i];
			--frc.back();
		}
	else
	{
		frc.back() -= diff;
		for (int i = 0; i < diff; ++i)
			++frc[frc.size() - 1 - i];
	}
}

int main()
{
	int n;
	cin >> n;
	srch(n);
	cout << frc[0];
	for (int i = 1; i < frc.size(); ++i)
		cout << ' ' << frc[i];
	cout << endl;
}
