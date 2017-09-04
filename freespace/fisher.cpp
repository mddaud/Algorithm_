/**
	http://www.spoj.com/problems/FISHER/
	
	Dynamic Programming 
*/

#include "bits/stdc++.h"
#define ll long long
#define mp make_pair
using namespace std;

const int inf = 10000;
int timeto[55][55];
int toll[55][55];
vector<pair<int, int> >memo[550];
int x, y;

void setv() {
	for(int i = 0; i < 550; i++) {
		memo[i].resize(550);
	}
	for(int i = 0; i < 550; i++) for(int j = 0; j < 550; j++) memo[i][j] = mp(-1, -1);
}

pair<int, int> F(int curr, int t_left) {
	if(t_left < 0) return {inf, inf};
	if(curr == x-1) return {0, 0};
	if(memo[curr][t_left] != mp(-1, -1)) return memo[curr][t_left];
	pair<int, int> ans = {inf, inf};
	
	for(int i = 0; i < x; i++) {
		if(curr != i) {
			pair<int, int> nextcity = F(i, t_left - timeto[curr][i]);
			if(nextcity.first + toll[curr][i] < ans.first) {
				ans.first  = nextcity.first  +   toll[curr][i];
				ans.second = nextcity.second +   timeto[curr][i];
			}
		}
	}
	return memo[curr][t_left] = ans;
}

int main() {
	
	while(1) {
		setv();
		scanf("%d%d",&x,&y);
		if(x == 0 && y == 0) break;
		for(int i = 0; i < x; i++) for(int j = 0; j < x; j++) scanf("%d", &timeto[i][j]);
		for(int i = 0; i < x; i++) for(int j = 0; j < x; j++) scanf("%d", &toll[i][j]);
		
		pair<int, int> Ans = F(0, y);
		cout << Ans.first << " " << Ans.second << '\n';
	}
	
	return 0;
}
