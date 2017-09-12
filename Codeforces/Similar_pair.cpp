/**
	*Similar pair Hackerrank
	*https://www.hackerrank.com/challenges/similarpair/problem
	
	*DFS + SEGMENT TREE
*/

	
#include "bits/stdc++.h"
#define ll long long
#define eb push_back
#define mp make_pair
using namespace std;

const int sz = 1e5+10;
ll ans = 0;
vector<int> V[sz];
int n, k;
int tree[4*sz];

void update(int id, int l, int r, int pos, int val) {
	if(pos < l || pos > r) return;	
	if(l == r && l == pos) {
		tree[id] = val;
		return;
	}
	int mid = (l+r) / 2;
	update(2*id, l, mid, pos, val);
	update(2*id+1, mid+1, r, pos, val);
	tree[id] = tree[2*id] + tree[2*id+1];
}

int query(int id, int a, int b, int l, int r) {
	if(l <= a && b <= r) return tree[id];
	if(a > r || b < l) return 0;
	int mid = (a + b) / 2;
	return query(2*id, a, mid, l, r) + query(2*id+1, mid+1, b, l, r);
}

void dfs(int u) {
	cout << ans << '\n';
	ans += query(1, 1, n, max(1, u-k), min(n, u+k));
	update(1, 1, n, u, 1);
	int sz = V[u].size();
	for(int i = 0; i < sz; i++) {
		int v = V[u][i];
		dfs(v);
	}
	update(1, 1, n, u, 0);
}

int main() {
	int root;
	bool isr[sz];
	cin >> n >> k;
	for(int i = 0; i <= n; i++) isr[i] = false;
	for(int i = 0; i <= 3*sz; i++) tree[i] = 0;
	for(int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;
		V[x].eb(y);
		isr[y] = true;
	}
	for(int i = 1; i <= n; i++) {
		if(!isr[i]) {
			root = i;
			break;
		}
	}
	//cout << root;
	dfs(root);
	cout << ans;
	return 0;
}
