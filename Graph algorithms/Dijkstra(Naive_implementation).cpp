#include <bits/stdc++.h>

using namespace std;

int n, m, start, finish;
vector<vector<pair<int, int> > > G;

void dijkstra(int n, int m, int start, vector<int>& d, vector<int>& p, vector<vector<pair<int, int> > >& G){
    d.resize(n+1);
    p.resize(n+1);

    fill(d.begin(), d.end(), 1e9);
    vector<int> used(n+1, 0);
    d[start] = 0;
    p[start] = -1;

    for(int i=1;i<=n;i++){
        int mn = 1e9, v = 0;

        for(int j=1;j<=n;j++){
            if(used[j] == 0 && d[j] < mn){
                mn = d[j];
                v = j;
            }
        }

        for(int k=0;k<G[v].size();k++){
            int to = G[v][k].first, len = G[v][k].second;
            if(d[v] + len < d[to]){
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
        used[v] = 1;
    }

}

int main(){
    cin >> n >> m;
    G.resize(n+1);

    for(int u, v, w, i=1; i<=m; i++){
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    cin >> start >> finish;

    vector<int> dist, parent, path;

    dijkstra(n, m, start, dist, parent, G);

    if(dist[finish] == 1e9){
        cout << "No path";
        return 0;
    }

    int cur = finish;
    do{
        path.push_back(cur);
        cur = parent[cur];
    }while(cur!=-1);

    reverse(path.begin(), path.end());

    cout << dist[finish] << endl;

    for(int node : path){
        cout << node << ' ';
    }

    return 0;
}