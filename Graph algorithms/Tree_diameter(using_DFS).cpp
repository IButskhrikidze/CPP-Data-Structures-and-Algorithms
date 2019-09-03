#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, mx, ind;
vector<int> G[100001], volume(100001);

void DFS(int v,int e){
	for(int x : G[v])
		if(x!=e){
			volume[x] = volume[v] + 1;
			DFS(x,v);
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
	
	for(int i=1;i<=n;i++){
		if(mx<volume[i]){
			mx = volume[i];
			ind = i;
		}
		volume[i] = 0;
	}
	
	DFS(ind,0);
	
	mx = 0;
	
	for(int i=1;i<=n;i++)
		mx = max(mx,volume[i]);
		
	cout << mx;
	
return 0;
}
