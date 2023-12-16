#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define int long long

/*
kactl
*/

struct DSU {
	vector<int> e; void init(int N) { e = vector<int>(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n, m; cin >> n >> m;
	vector<pair<pair<int, int>, int> > edg;
	while (m--) {
		int u, v, w; cin >> u >> v >> w; u--; v--;
		edg.push_back(make_pair(make_pair(u, v), w));
	}
	graph gr(n, edg);
	vector<int> ans = gr.dij2(0);
	for (auto i : ans) cout << i << " ";
	
	return 0;
}
