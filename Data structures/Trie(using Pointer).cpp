#include <bits/stdc++.h>

using namespace std;

int q;

struct Node{
	int deg, end;
	Node *child[26];
	Node (){
		for (int i = 0; i < 26; i++)
			child[i] = NULL;
		end = 0;
		deg = 0;
	}
};

Node *root = new Node;


void Insert(string s){
	Node *to = root;
	for(int i=0;i<s.size();i++){
		int k = s[i]-'a';
		if(to->child[k]==NULL)
			to->child[k] = new Node;
		to = to->child[k];
		to->deg++;
	}
	to->end++;
}

int Search(string s){
	Node *to = root;
	for(int i=0;i<s.size();i++){
		int k = s[i]-'a';
		if(to->child[k]==NULL)
			return 0;
		to = to->child[k];
	}
	return to->end;
}

void Delete(string s){
	Node *to = root;
	for(int i=0;i<s.size();i++){
		int k = s[i]-'a';
		if(to->child[k]->deg==1){
			to->child[k] = NULL;
			break;
		}
		to = to->child[k];
		to->deg--;
	}
	to->end--;
}

int main(){
	cin >> q;
	
	while(q--){
		string id, s;
		cin >> id >> s;
		if(id=="Insert")
			Insert(s);
		if(id=="Search")
			cout << "\nWas Found: " << Search(s) << '\n';
		if(id=="Delete")
			Delete(s);
	}
	
return 0;
}
