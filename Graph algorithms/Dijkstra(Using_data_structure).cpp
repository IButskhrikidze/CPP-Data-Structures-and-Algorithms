#include <bits/stdc++.h>

using namespace std;

int n, m, start, finish;
vector<vector<pair<int, int> > > G;

void dijkstra(int n, int m, int start, vector<int>& d, vector<int>& p, vector<vector<pair<int, int> > >& G){
    d.resize(n+1);
    p.resize(n+1);

    fill(d.begin(), d.end(), 1e9);
    set<pair<int, int> > st;

    d[start] = 0;
    p[start] = -1;

    st.insert({d[start], start});

    while(!st.empty()){
        int v = st.begin()->second;
        st.erase(st.begin());

        for(int i=0;i<G[v].size();i++){
            int to = G[v][i].first, len = G[v][i].second;

            if(d[v] + len < d[to]){
                st.erase({d[to], to});
                d[to] = d[v] + len;
                st.insert({d[to], to});
                p[to] = v;
            }
        }
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