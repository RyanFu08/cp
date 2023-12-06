
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfenv>
#include <cfloat>
#include <chrono>
#include <cinttypes>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <immintrin.h>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <streambuf>
#include <string>
#include <tuple>
#include <type_traits>
#include <variant>
using namespace std;

/*
Tree
- initializes from vector of edges in O(nlogn)
- performs lca in O(logn)
*/

struct tree {
	int n;
	vector<vector<int> > adj;
	vector<vector<int> > jump;
	vector<int> t1,t2; int t;
	tree() {}
	tree(vector<pair<int,int> > edges) {
		n=edges.size()+1;
		adj=vector<vector<int> >(n);
		for (auto i:edges) {
			adj[i.first].push_back(i.second);
			adj[i.second].push_back(i.first);
		}
		t1=vector<int>(n); t2=vector<int>(n);
		t=0; jump=vector<vector<int> >(n,vector<int>(ceil(log2(n))+1));
		dfs(0,0);
	}
	void dfs(int v, int p) {
		t1[v]=++t;
		jump[v][0]=p;
		for (int i=1; i<=ceil(log2(n)); i++) {
			jump[v][i]=jump[jump[v][i-1]][i-1];
		}
		for (auto u:adj[v]) {
			if (u!=p) dfs(u,v);
		}
		t2[v]=++t;
	}
	bool ancestor(int u, int v) {
		return t1[u]<=t1[v] && t2[u]>=t2[v];
	}
	int lca(int u, int v) {
		if (ancestor(u,v)) return u;
		if (ancestor(v,u)) return v;
		for (int i=ceil(log2(n)); i>=0; --i) {
			if (!ancestor(jump[u][i],v)) u=jump[u][i];
		}
		return jump[u][0];
	}
};

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	vector<pair<int,int> > a;
	a.push_back(make_pair(0,1));
	a.push_back(make_pair(0,2));
	a.push_back(make_pair(1,3));
	tree x(a);
	cout<<x.lca(2,3);
	return 0;
}
