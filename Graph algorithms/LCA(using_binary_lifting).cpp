#include<bits/stdc++.h>

using namespace std;

int n, P[10001][40];
vector<int> G[100001], volume(100001);

void DFS(int v, int e) {
    P[v][0] = e;
    for (int x : G[v])
        if (x != e) {
            volume[x] = volume[v] + 1;
            DFS(x, v);
        }
}

void Prepare() {
    DFS(1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = 0; (1 << j) < n; j++)
            P[i][j] = -1;

    for (int j = 1; (1 << j) < n; j++)
        for (int i = 1; i <= n; i++)
            if (P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
}

int LCA(int u, int v) {
    if (volume[u] < volume[v])
        swap(u, v);
    int k = volume[u] - volume[v];
    while (k > 0) {
        int t = log2(k);
        u = P[u][t];
        k -= (1 << t);
    }
    if (u == v)
        return u;
    k = log2(n);
    for (int j = k; j >= 0; j--)
        if (P[v][j] != P[u][j]) {
            u = P[u][j];
            v = P[v][j];
        }
    return P[u][0];
}

int main() {
    cin >> n;
    for (int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    Prepare();
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << endl;
    }
    return 0;
}
