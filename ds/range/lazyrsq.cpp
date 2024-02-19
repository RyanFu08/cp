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
0 indexed Range Sum Query
update(l,r,v) adds v to range [l,r]
query(l,r) returns sum from [l,r]
verified on spoj: https://www.spoj.com/status/ns=32641485
*/

struct SegmentTree {
    int n; vector<int> tree, lazy;
    SegmentTree(int size) : n(size), tree(4 * n), lazy(4 * n) {}
    void propagate(int node, int start, int end) { if (lazy[node]) { tree[node] += (end - start + 1) * lazy[node]; if (start != end) { lazy[2 * node] += lazy[node]; lazy[2 * node + 1] += lazy[node]; } lazy[node] = 0; } }
    void updateRange(int node, int start, int end, int l, int r, int val) { propagate(node, start, end); if (start > r || end < l) return; if (start >= l && end <= r) { tree[node] += (end - start + 1) * val; if (start != end) { lazy[2 * node] += val; lazy[2 * node + 1] += val; } return; } int mid = (start + end) / 2; updateRange(2 * node, start, mid, l, r, val); updateRange(2 * node + 1, mid + 1, end, l, r, val); tree[node] = tree[2 * node] + tree[2 * node + 1]; }
    int queryRange(int node, int start, int end, int l, int r) { propagate(node, start, end); if (start > r || end < l) return 0; if (start >= l && end <= r) return tree[node]; int mid = (start + end) / 2; return queryRange(2 * node, start, mid, l, r) + queryRange(2 * node + 1, mid + 1, end, l, r); }
    void update(int l, int r, int val) { updateRange(1, 0, n - 1, l, r, val); }
    int query(int l, int r) { return queryRange(1, 0, n - 1, l, r); }
};


signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	return 0;
}
