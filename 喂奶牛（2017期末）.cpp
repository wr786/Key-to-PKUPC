
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

int qgetint()		// 快读，理论上快于iostream
{
	int num = 0, sign = 1;
	int ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar())
		if (ch == '-')
			sign = -1;
		else
			sign = 1;
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		num = num * 10 + ch - '0';
	return num * sign;
}

#define verify(x) assert(x)

// 流量网络中的边（有向边）
class flow_edge
{
private:
	int _v, _w;
	double _cap, _flow;
public:
	flow_edge() { }
	flow_edge(int v, int w, double capacity)
		:_v(v), _w(w), _cap(capacity), _flow(0)
	{}
	int from() const { return _v; }
	int to() const { return _w; }
	int other(int v) const {
		return v == _v ? _w : _v;
	}
	double capacity() const { return _cap; }
	double flow() const { return _flow; }
	double res_capacity_to(int v) const
	{
		verify(v == _v || v == _w);
		if (v == _v)return flow();
		else return capacity() - flow();
	}
	void add_flow_to(int v, double delta)
	{
		verify(v == _v || v == _w);
		if (v == _v)_flow -= delta;
		else _flow += delta;
	}
};

// 流量网络（加权无向图）
class flow_network
{
private:
	int _V, _E;
	valarray<vector<flow_edge*> > _adjs; //邻接表
public:
	flow_network(int V, int E = 0) :
		_V(V), _E(E), _adjs(V)
	{}
	flow_network(int V, int E, valarray<vector<flow_edge*> >& adjs) :
		_V(V), _E(E), _adjs(adjs)
	{}
	int V() const { return _V; }
	int E() const { return _E; }
	void add_edge(flow_edge& fe)
	{
		int v = fe.from(), w = fe.to();
		_adjs[v].push_back(&fe);
		_adjs[w].push_back(&fe);
		++_E;
	}
	vector<flow_edge*>& adjs(int v) { return _adjs[v]; }
};

const double inf = INFINITY;

class ford_fulkerson_processer
{
private:
	valarray<bool> marked;
	valarray<flow_edge*> edge_to;
	double val;
	bool has_aug_path(flow_network& fn, int source, int dest)		// 找到可行通路
	{
		marked.resize(fn.V(), false);
		edge_to.resize(fn.V());
		queue<int> que;
		marked[source] = true;
		que.push(source);

		for (; que.size();)
		{
			int v = que.front();
			que.pop();
			vector<flow_edge*>& adjs = fn.adjs(v);
			for (int i = 0; i < adjs.size(); ++i)
			{
				flow_edge* fe = adjs[i];
				int w = fe->other(v);
				if (fe->res_capacity_to(w) > 0 && !marked[w])
				{
					marked[w] = true;
					edge_to[w] = fe;
					que.push(w);
				}
			}
		}

		return marked[dest];
	}
public:
	ford_fulkerson_processer(flow_network& fn, int s, int d)
		:marked(fn.V()), edge_to(fn.V()), val(0)
	{
		for (; has_aug_path(fn, s, d);)
		{
			double bottle = inf;	// 瓶颈流量
			for (int v = d; v != s; v = edge_to[v]->other(v))
				bottle = min(bottle, edge_to[v]->res_capacity_to(v));
			for (int v = d; v != s; v = edge_to[v]->other(v))
				edge_to[v]->add_flow_to(v, bottle);
			val += bottle;
		}
	}
	double value() const { return val; }
};

void del_all(const vector<flow_edge*>& _for_del)
{
	for (int i = 0; i < _for_del.size(); ++i)
		delete _for_del[i];
}

// 网络结构：
// source
// 食物 F个点
// 奶牛 N个点
// 奶牛 N个点
// 饮料 D个点
// dest

int main()
{
	int F, D, N;
	cin >> N >> F >> D;
	const int v_src = 0, v_dest = F + N + N + D + 1;
	flow_network fn(F + N + N + D + 2);

	vector<flow_edge*> _for_del;		// 为了保存我的声誉（大雾），还是写一个防止内存泄漏的吧（

	for (int fidx = 1; fidx <= F; ++fidx)
	{
		flow_edge& fe0 = *new flow_edge(v_src, fidx, 1);
		fn.add_edge(fe0);
		_for_del.push_back(&fe0);
	}

	for (int i = 0; i < N; ++i)
	{
		int Fi = qgetint(), Di = qgetint();
		for (int j = 0; j < Fi; ++j)
		{
			int fidx = qgetint();
			flow_edge& fe1 = *new flow_edge(fidx, 1 + F + i, 1);
			fn.add_edge(fe1);
			_for_del.push_back(&fe1);
		}
		flow_edge& fe2 = *new flow_edge(1 + F + i, 1 + F + N + i, 1);
		fn.add_edge(fe2);
		_for_del.push_back(&fe2);
		for (int j = 0; j < Di; ++j)
		{
			int didx = qgetint() + F + N + N;
			flow_edge& fe3 = *new flow_edge(1 + F + N + i, didx, 1);
			fn.add_edge(fe3);
			_for_del.push_back(&fe3);
		}
	}

	for (int didx = F + N + N + 1; didx < v_dest; ++didx)
	{
		flow_edge& fe4 = *new flow_edge(didx, v_dest, 1);
		fn.add_edge(fe4);
		_for_del.push_back(&fe4);
	}

	ford_fulkerson_processer ffp(fn, v_src, v_dest);
	cout << ffp.value() << endl;

	del_all(_for_del);
}
