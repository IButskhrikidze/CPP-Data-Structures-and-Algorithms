#include <bits/stdc++.h>

using namespace std;

int n, m, used[101];
vector < int > g[100], Sort;

void DFS(int v){
	used[v] = 1;
	for(int i=0;i<g[v].size();i++)
		if(!used[g[v][i]])
			DFS(g[v][i]);
	Sort.push_back(v);
}

int main(){
	cin >> n >> m;
	for(int x,y,i=1;i<=m;i++){
		cin >> x >> y;
		g[x].push_back(y);
	}
	for(int i=1;i<=n;i++)
		if(!used[i])
			DFS(i);
			
	reverse(Sort.begin(),Sort.end());
	
	for(int x : Sort)
		cout << x << ' ';
	
return 0;
}

/*
7 8
1 2
1 5
2 3
2 7
3 7
4 3
4 5
7 6
*/

