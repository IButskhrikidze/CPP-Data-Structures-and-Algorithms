#include<iostream>
#include<queue>
using namespace std;

int s,n,G[1001][1001],vis[1001],p[1001];
queue<int>q;
void BFS(int s,int G[1001][1001]){
	q.push(s);
	vis[s]=1;
	p[s]=0;
	while(!q.empty()){
		int v=q.front();
		q.pop();
		for(int i=1;i<=n;i++){
			if(G[v][i]==1 && vis[i]==0){
				vis[i]=1;
				q.push(i);
				p[i]=v;
			}
	 }
	}
}
int main(){
cin>>n>>s;
for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		cin>>G[i][j];
BFS(s,G);
for(int i=1;i<=n;i++)
	cout<<p[i]<<" ";
return 0;
}
/*
10
0 0 1 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0 0
1 0 0 0 0 0 0 0 0 1
0 0 0 0 1 1 1 0 0 0
0 1 0 1 0 0 0 1 0 1
0 0 0 1 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0
0 0 0 0 1 0 0 0 1 0
0 0 0 0 0 0 0 1 0 0
0 0 1 0 1 0 0 0 0 0
*/
