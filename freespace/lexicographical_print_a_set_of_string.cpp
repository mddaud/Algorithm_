/**
   Lexicographically Print a set of keys
   
   Sample:
   		   //Input              //Output
   		   john			 boo
   		   tex			 book
   		   boo			 booking
   		   book			 john
   		   text			 tex
   		   booking		 text
   	
   	Fisrt Insert all key on trie then traverse the tree
*/

#include "bits/stdc++.h"
#define ll long long
using namespace std;

struct TrieNode {
	bool flag;
	TrieNode* a[26];
	
	TrieNode() {
		flag = false;
		for(int i = 0; i < 26; i++){
			a[i] = NULL;
		}
	}
};

TrieNode* insert(int idx, string &S, TrieNode* root) {
	if(idx == S.length()) {
		root -> flag = true;
		return root;
	}
	int curr = S[idx] - 'a';
	if(root -> a[curr] == NULL) root -> a[curr] = new TrieNode;
	insert(idx+1, S, root -> a[curr]);
	return root;
}

void lexicographical_printing(TrieNode* root, string hold) {
	if(root -> flag == true){
		cout << hold << '\n';
	}
	
	for(int i = 0; i < 26; i++){
		if(root -> a[i] == NULL) continue;
		char to_add = 'a' + i;
		string temp = hold + to_add;
		lexicographical_printing(root -> a[i], temp);
	}
}


int main(){
	int n;
	cin >> n;
	TrieNode* root = new TrieNode;
	while(n--) {
		string str;
		cin >> str;
		root = insert(0, str, root);
	}
	string hold;
	lexicographical_printing(root, hold);
	return 0;
}
