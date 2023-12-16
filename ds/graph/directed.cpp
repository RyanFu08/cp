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
Directed Graph
- intializes from number of nodes, adjacency (O(n))
- finds topsort order in O(E + V) (untested)
- finds sccs in O(E + V) (verified: https://cses.fi/problemset/hack/1683/entry/7949180/)
*/

struct directed {
	int n; vector<vector<int> > adj;
	vector<vector<int> > rev;
	vector<bool> vis;
	vector<int> ord;
	vector<int> con;
	directed(int n1, vector<vector<int> > adj1) {
		n = n1; adj = adj1; rev = vector<vector<int> >(n);
		for (int i = 0; i < n; i++) {
			for (auto j : adj[i]) {
				rev[j].push_back(i);
			}
		}
	}
	vector<int> topsort() {
		vector<int> deg(n, 0);
		for (int i = 0; i < n; i++) {
			deg[i] = rev[i].size();
		}
		vector<int> res;
		for (int i = 0; i < n; i++) {
			if (!deg[i]) res.push_back(i);
		}
		int cp = 0;
		while (cp < res.size()) {
			int v = res[cp];
			for (auto i : adj[v]) {
				deg[i]--;
				if (!deg[i]) res.push_back(i);
			}
			cp++;
		}
		return res;
	}
	void dfs1(int v) {
		vis[v] = 1;
		for (auto u : adj[v]) {
			if (!vis[u]) dfs1(u);
		}
		ord.push_back(v);
	}
	void dfs2(int v) {
		vis[v] = 1;
		con.push_back(v);
		for (auto u : rev[v]) {
			if (!vis[u]) dfs2(u);
		}
	}
	
	vector<vector<int> > scc() {
		vis = vector<bool>(n, 0);
		ord = vector<int>();
		for (int i = 0; i < n; i++) {
			if (!vis[i]) dfs1(i);
		}
		vis = vector<bool>(n, 0);
		reverse(ord.begin(), ord.end());
		vector<vector<int> > res;
		for (auto i : ord) {
			con.clear();
			if (!vis[i]) {
				dfs2(i);
				res.push_back(con);
			}
		}
		return res;
	}
	
};

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	return 0;
}
