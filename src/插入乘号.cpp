
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

int max_prod(const string& s, int k)
{
	if (k == 0)
		return atoi(s.c_str());
	int n = s.size();
	int ret = 0;
	for (int i = 1; i < n; ++i)
	{
		string before;
		for (int j = 0; j < i; ++j)
			before.push_back(s[j]);
		string after = s.substr(i);
		for (int j = 0; j <= k - 1; ++j)
		{
			ret = max(ret,
				max_prod(before, j) * max_prod(after, k - 1 - j)
			);
		}
	}
	return ret;
}

int main()
{
	string s;
	int k;
	cin >> s >> k;
	cout << max_prod(s, k) << endl;
}
