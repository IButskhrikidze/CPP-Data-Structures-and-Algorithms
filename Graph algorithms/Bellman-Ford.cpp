#include <bits/stdc++.h>
#define inf 10000000

using namespace std;

int n, m, start, End;
struct Edge{
	int u, v, w;
};

vector<Edge> e;
vector<int> d(10000,inf);
vector<int> parent(10000,-1);

int main(){
	cin >> n >> m;
	for(int x,y,w,i=1;i<=m;i++){
		cin >> x >> y >> w;
		e.push_back({x,y,w});
	}
		
	cin >> start >> End;
	d[start] = 0;
	
	for(int i=1;i<=n;i++){
		bool ind = false;
		for(int j=0;j<e.size();j++){
			if(d[e[j].u]<inf){
				if(d[e[j].v]>d[e[j].u]+e[j].w){
					d[e[j].v] = d[e[j].u]+e[j].w;
					parent[e[j].v] = e[j].u;
					ind = true;
				}
			}	
		}
		if(!ind)
			break;	
	}
	
	if(d[End]==inf){
		cout << "No path from " << start << " to " << End << ".";
	}else{
		vector<int> path;
		for (int cur=End; cur!=-1; cur=parent[cur])
			path.push_back (cur);
			
		cout << "Path from " << start << " to " << End << ": ";
		for (int i=path.size(); i>=0; i--)
			cout << path[i] << ' ';
	}
	
return 0;
}
