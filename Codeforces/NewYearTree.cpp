/**
    http://codeforces.com/problemset/problem/620/E
    DFS - ON -TREE + segment tree + Lazy - Propogation
    
    First Convert subtree to subarray by dfs then 
    apply segment tree on subarray
*/
    
#include "bits/stdc++.h"
#define ll long long
#define eb emplace_back
using namespace std;
vector<ll> V[16*100003];
ll tin[16*100003], tout[16*100003], tour[16*100003], tree[16*100003], lazy[16*100003], a[16*100003], tt = 1;

void dfs(ll u, ll pr){
	tour[tt] = u;
	tin[u] = tt++;
	ll sz = V[u].size();
	for(ll i = 0; i < sz; i++){
		ll k = V[u][i];
		if(k != pr){
			dfs(V[u][i],u);
		}
	}
	tout[u] = tt;
	return;
}

void build(ll id,ll l, ll r){
	if(l == r){
    tree[id] = 1ll << a[tour[l]];
	}
	else{
		ll mid = (l + r) / 2;
		build(2 * id, l, mid);
		build(2 * id + 1, mid + 1, r);
		tree[id] = tree[2* id] | tree[2 * id + 1];
	}
}

void shift(ll id){
	if(lazy[id] == 0) return;
	tree[2 * id] = 1ll << lazy[id];
	tree[2 * id + 1] = 1ll << lazy[id];
	lazy[2 * id] = lazy[id];
	lazy[2 * id + 1] = lazy[id];
	lazy[id] = 0;
	return;
}

void update(ll id, ll a, ll b, ll l, ll r, ll x){
	if(l > b || r < a) return;
	if(a >=l && b <= r){
		tree[id] = 1ll << x;
		lazy[id] = x;
		return;
	}
	shift(id);
	ll mid = (a + b) / 2;
	update(2 * id, a, mid, l, r, x);
	update(2 * id + 1, mid + 1, b, l, r, x);
	tree[id] = tree[2 * id] | tree[2 * id + 1];
	return;
}

ll query(ll id, ll a, ll b, ll l, ll r){
	if(l > b || r < a) return 0;
	if(a >= l && b <= r) return tree[id];
	shift(id);
	ll mid = (a + b) / 2;
	ll ANS1 = query(2 * id, a, mid, l, r);
	ll ANS2 = query(2 * id + 1, mid + 1, b, l, r);
	return ANS1 | ANS2;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(lazy,0,sizeof lazy);
	ll n, m;
	cin >> n >> m;
	for(ll i =1; i <= n; i++) cin >> a[i];
	ll x = n-1;
	while(x--){
		ll u, v;
		cin >> u >> v;
		V[u].eb(v);
		V[v].eb(u);
	}
	dfs(1,-1);
	build(1, 1, n);
	while(m--){
		ll type;
		cin >> type;
		if(type == 1){
			ll aa, ba;
			cin >> aa >> ba;
			ll start = tin[aa];
			ll end = tout[aa] - 1;
			update(1, 1, n, start, end, ba);
		}
		if(type == 2){
			ll aa;
			cin >> aa;
			ll start = tin[aa];
			ll end = tout[aa] - 1;
			cout << __builtin_popcountll(query(1, 1, n, start, end)) << '\n';
		}
	}
	return 0;
}
