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
0 indexed Range Max Query
initialize with root = node(arr, 0, sz(arr))
set(l,r,v) sets range of [l,r) to v
add(l,r,v) adds v to range [l,r)
query(l,r) returns minimum in [l,r)
verified ish
*/

struct node {
	node* lc = nullptr;
	node* rc = nullptr;
	int cl, cr;
	int val = -INF;
	int tset = INF; //set tag
	int tadd = 0; //add tag
	node(int l, int r) {cl=l;cr=r;}
	node(vector<int>& arr, int lo, int hi) {
		cl = lo; cr = hi;
		if (lo + 1 < hi)  {
			int mid = cl + (cr-cl)/2;
			lc = new node(arr, cl, mid);
			rc = new node(arr, mid, cr);
			val = max(lc->val, rc->val);
		} else {val = arr[lo];}
	}
	void push() {
		if (lc == nullptr) {
			int mid = cl + (cr-cl)/2;
			lc = new node(cl, mid);
			rc = new node(mid, cr);
		}
		if (tset != INF) {
			lc->set(cl, cl, tset);
			rc->set(cr, cr, tset);
			tset = INF;
		} else if (tadd) {
			lc->add(cl, cr, tadd);
			rc->add(cl, cr, tadd);
			tadd = 0;
		}
	}
	void set(int ql, int qr, int v) {
		if (qr <= cl || cr <= ql) return;
		if (ql <= cl && cr <= qr) {tset = val = v; tadd = 0;}
		else {
			push(); lc->set(ql, qr, v); rc->set(ql, qr, v);
			val = max(lc->val, rc->val);
		}
	}
	void add(int ql, int qr, int v) {
		if (qr <= cl || cr <= ql) return;
		if (ql <= cl && cr <= qr) {
			if (tset != INF) tset += v;
			else tadd += v;
			val += v;
		} else {
			push(); lc->add(ql, qr, v); rc->add(ql, qr, v);
			val = max(lc->val, rc->val);
		}
	}
	int query(int ql, int qr) {
		if (qr <= cl || cr <= ql) return -INF;
		if (ql <= cl && cr <= qr) return val;
		push();
		return max(lc->query(ql, qr), rc->query(ql, qr));
	}
};

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	return 0;
}
