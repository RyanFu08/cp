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

/*
Weighted Graph
- initializes from number of nodes, vector of (weighted) edges in O(n)
- performs dijkstra in O(ElogV) (verified: https://cses.fi/problemset/hack/1671/entry/7941492/)
- performs dijkstra in O(V^2) (semi-verified: https://cses.fi/problemset/result/7941658/)
- performs kruskal in O(E * \alpha(V)) (verified: https://cses.fi/problemset/task/1675/)
*/

struct graph {
	int n; int INF = 1e18;
	vector<vector<pair<int, int> > > adj;
	vector<pair<int, pair<int, int> > > edg;
	graph() {}
	graph(int n1, vector<pair<pair<int, int>, int> > edges) {
		n = n1; adj = vector<vector<pair<int, int> > >(n);
		for (auto i : edges) {
			edg.push_back(make_pair(i.second, i.first));
			adj[i.first.first].push_back(make_pair(i.first.second, i.second));
			adj[i.first.second].push_back(make_pair(i.first.first, i.second));
		}
	}
	vector<int> dij1(int src) {
		vector<int> dist(n, INF);
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > dij;
		dij.push(make_pair(0, src));
		while (!dij.empty()) {
			int d = dij.top().first;
			int v = dij.top().second;
			dij.pop();
			if (dist[v] <= d) continue;
			dist[v] = d;
			for (auto i : adj[v]) {
				if (dist[i.first] == INF) dij.push(make_pair(d + i.second, i.first));
			}
		}
		return dist;
	}
	vector<int> dij2(int src) {
		vector<int> dist(n, INF);
		int cpos = -1;
		int npos = src;
		dist[npos] = 0;
		vector<bool> vis(n, 0);
		for (int i = 0; i < n; i++) {
			cpos = npos; npos = -1;
			vis[cpos] = 1;
			for (auto j : adj[cpos]) {
				dist[j.first] = min(dist[j.first], j.second + dist[cpos]);
			}
			for (int j = 0; j < n; j++) {
				if (!vis[j]) {
					if (npos == -1) npos = j;
					if (dist[j] < dist[npos]) npos = j;
				}
			}
		}
		return dist;
	}
	vector<pair<int, pair<int, int> > > kruskal() {
		vector<pair<int, pair<int, int> > > ans;
		DSU d; d.init(n);
		sort(edg.begin(), edg.end());
		for (auto i : edg) {
			if (d.sameSet(i.second.first, i.second.second)) continue;
			ans.push_back(i);
			d.unite(i.second.first, i.second.second);
		}
		return ans;
	}
};

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	return 0;
}