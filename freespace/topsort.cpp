/**
  * Topological Sorting Of DAG 
  * Lexicographical order
  * Use set Instead of Queue
  * Other Way of Finding topological sorting is DFS
  * Linear time
  *
  *http://www.spoj.com/problems/TOPOSORT/
  */
  
#include "bits/stdc++.h"
#define ll long long
#define eb emplace_back
using namespace std;

vector<int> V[100009];
int indeg[100009];
set<int> s;
vector<int> Ans;
int cnt = 0;
int n, m, x, y;

void topsort() {
	cnt = 0;
	set<int> :: iterator it;
	while(!s.empty()) {
		int u = *s.begin();
		s.erase(s.begin());
		Ans.eb(u);
		cnt++;
		int sz = V[u].size();
		for(int i = 0; i < sz; i++) {
			indeg[V[u][i]]--;
			if(!indeg[V[u][i]]) {
				s.insert(V[u][i]);
			}
		}
		
	}
}

int main() {
	scanf("%d%d",&n,&m);
	
	while(m--) {
		scanf("%d%d",&x,&y);
		indeg[y]++;
		V[x].eb(y);
	}
	
	for(int i = 1; i <= n; i++) {
		if(indeg[i] == 0) {
			s.insert(i);
		}
	}
	
	topsort();
	
	if(cnt != n) {
		printf("Sandro fails.");
	}
	else {
		for(int i = 0; i < n; i++) printf("%d ", Ans[i]);
	}
	return 0;
}
