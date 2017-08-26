/**
	*Lowest Common Ancestor 
	*First step  :- Store Depth and 2^0 or Immediate Parent of Every Node
	*Second step :- Find parent at level 2^i for every node
	*Third step  :- For Lca of u and v make level of u and v same by lifting
	*
	*Then simply Lca
	*Root Node is considered as 0
	*Complexity :- O((N+Q * log(N)))
	
	Spoj - Problem ( LCASQ)     http://www.spoj.com/problems/LCASQ/
	
*/


#include "bits/stdc++.h"
#define ll long long
using namespace std;

const int NMAX = 10000;
const int LGNMAX = 15;

vector<int> adjlist[NMAX];
int depth[NMAX];
int parent[LGNMAX][NMAX];
bool seen[NMAX];

int N, m, tt;

/************************************* LOWEST - COMMON - ANCESTOR ***************************************/
void dfs(int u) {
	seen[u] = true;
	int sz = adjlist[u].size();
	for(int i = 0; i < sz; i++) {
		int v = adjlist[u][i];
		if(seen[v]) continue;
		depth[v] = depth[u] + 1;
		parent[0][v] = u;
		dfs(v);
	}
}

void pre(){
	for(int i = 1; i < LGNMAX; i++) {
		for(int j = 0; j < N; j++) {
			if(parent[i-1][j] != -1) {
				parent[i][j] = parent[i-1][parent[i-1][j]];
			}
		}
	}
}

int getparent(int u, int k) {
	for(int i = 0; i < LGNMAX; i++) {
		if(k & 1) u = parent[i][u];
		k >>= 1;
	}
	return u;
}

int LCA(int u, int v) {
	if(depth[u] > depth[v]) {
		u = getparent(u, depth[u] - depth[v]);
	}
	if(depth[v] > depth[u]) {
		v = getparent(v, depth[v] - depth[u]);
	}
	
	if(u == v) return u;
	
	for(int i = LGNMAX-1; i >= 0; i--) {
		if(parent[i][u] != parent[i][v]) {
			u = parent[i][u];
			v = parent[i][v];
		}
	}
	
	return parent[0][u];
}

/*******************************************************************************************************/
int main() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		int x;
		cin >> x;
		while(x--) {
			cin >> tt;
			adjlist[i].push_back(tt);
			adjlist[tt].push_back(i);
		}
	}
	dfs(0);
	pre();
	
	cin >> m;
	while(m--) {
		int u, v;
		cin >> u >> v;
		cout << LCA(u, v) << '\n';
	}
	
	return 0;
}
