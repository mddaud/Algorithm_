/**
   No of Distinct substring in a string
   Sample case :
   		ABABA - 9
   		CCCCC - 5
   	
   Asuuming letter only consist of capital letters
   Insert all suffix into trie + count no of nodes in trie
*/

#include "bits/stdc++.h"
#define ll long long
#define K ll t; cin>>t; while(t--)
using namespace std;

struct TrieNode {
	TrieNode* a[26];
	
	TrieNode() {
		for(int i = 0; i < 26; i++){
			a[i] = NULL;
		}
	}
};

TrieNode* insert(int idx, string &S, TrieNode* root) {
	if(idx == S.length()) {
		return root;
	}
	int curr = S[idx] - 'A';
	if(root -> a[curr] == NULL) root -> a[curr] = new TrieNode;
	insert(idx+1, S, root -> a[curr]);
	return root;
}

int no_of_nodes(TrieNode* root) {
	int ans = 0;
	if(root == NULL) return 0;
	for(int i = 0; i < 26; i++) {
		if(root -> a[i] != NULL) {
			ans += no_of_nodes(root -> a[i]);
		}
	}
	return 1 + ans;
}

int main() {
	K{
		TrieNode* root = new TrieNode;
		string str;
		cin >> str;
		int l = str.length();
		for(int i = 0; i < l; i++) {
			string temp = str.substr(i, l-i);
			root = insert(0, temp, root);
		}
		cout << no_of_nodes(root) - 1 << '\n';
	}
	return 0;
}
