/**
   icpcarchive.ecs.baylor.edu/index.php
   
   Subarray With maximum Xor value
   Trie Solution
*/

#include "bits/stdc++.h"
#define ll long long
#define K ll t; cin>>t; while(t--)
using namespace std;

struct TrieNode{
	TrieNode* a[3];
	
	TrieNode() {
		for(int i = 0; i < 3; i++) {
			a[i] = NULL;
		}
	}
};

TrieNode* insert(int val, TrieNode* root, int idx) {
	if(idx == -1){
		return root;
	}
	int bitval;
	if(((1 << idx) & val) == (1 << idx)) bitval = 1;
	else bitval = 0;
	
	if(root -> a[bitval] == NULL) root -> a[bitval] = new TrieNode;
	insert(val, root -> a[bitval], idx-1);
	return root;
}

int query(TrieNode* root, int preXor) {
	TrieNode* curr = root;
	int res = 0;
	
	for(int i = 31; i >= 0; i--){
		int bitval;
		if(((1 << i) & preXor) == (1 << i)) bitval = 1;
		else bitval = 0;
	
		if(curr -> a[abs(1 - bitval)]) {
			curr = curr -> a[abs(1 - bitval)];
			res += (1 << i);
		}
		else curr = curr -> a[bitval];
	}
	return res;
}

	
int maXXor(vector<int> &V) {
	TrieNode* root = new TrieNode;
	root = insert(0, root, 31);
	int preXor = 0;
	int ans = INT_MIN;
	int sz = V.size();
	
	for(int i = 0; i < sz; i++) {
		preXor ^= V[i];
		root = insert(preXor, root, 31);
		
		ans = max(ans, query(root, preXor));
	}
	
	return ans;
}

int main() {
	K {
		int n;
		cin >> n;
		vector<int> V;
		for(int i = 0; i < n; i++) {
			int x;
			cin >> x;
			V.push_back(x);
		}
		cout <<  maXXor(V) << '\n';
	}
	return 0;
}
