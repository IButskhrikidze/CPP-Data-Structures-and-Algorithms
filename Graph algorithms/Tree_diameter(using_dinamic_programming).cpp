#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> G[100001], p(100001), d(100001);

void DFS(int v, int e){
	int mx = 0, mx1 = -1, mx2 = -1;
	
	for(int x : G[v]){
		if(x==e)
			continue;
		DFS(x,v);
		mx = max(mx,d[x]);
		if(mx1<=d[x]){
			if(mx1!=-1)
				mx2 = mx1;
			mx1 = d[x];
		}
	}
	
	if(G[v].size()==1 && v!=1){
		d[v] = 0; p[v] = 0;	
	}
	else{
		d[v] = mx+1; p[v] = mx1+mx2+2;
	}
}

int main(){
	cin >> n;
	for(int x,y,i=1;i<n;i++){
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
	DFS(1,0);
	
	int ans = 0;
	
	for(int i=1;i<=n;i++)
		ans = max(ans,p[i]);
		
	cout << ans;
return 0;
}
/*
15
1 2
1 8
2 3
2 4
2 6
3 5
4 7
8 9
8 10
10 11
11 12
12 13
13 14
14 15

*/
