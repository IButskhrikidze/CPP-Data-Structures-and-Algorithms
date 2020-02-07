#include <bits/stdc++.h>

using namespace std;

int n, m, q, used[100001], volume[100001], first[100001], t[400001];
vector<int> G[100001], order(1);

void DFS(int v) {
    used[v] = 1;
    order.push_back(v);
    for (int x : G[v])
        if (used[x] == 0) {
            volume[x] = volume[v] + 1;
            DFS(x);
            order.push_back(v);
        }
}


void build(int v, int tl, int tr) {
    if (tl == tr)
        t[v] = order[tl];
    else {
        int m = (tl + tr) / 2;
        build(2 * v, tl, m);
        build(2 * v + 1, m + 1, tr);
        if (volume[t[2 * v]] < volume[t[2 * v + 1]])
            t[v] = t[2 * v];
        else
            t[v] = t[2 * v + 1];
    }
}

int minimum(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r)
        return t[v];
    int tm = (tl + tr) / 2;
    if (r <= tm)
        return minimum(2 * v, tl, tm, l, r);
    if (l > tm)
        return minimum(2 * v + 1, tm + 1, tr, l, r);
    int ans1 = minimum(2 * v, tl, tm, l, tm);
    int ans2 = minimum(2 * v + 1, tm + 1, tr, tm + 1, r);
    return volume[ans1] < volume[ans2] ? ans1 : ans2;
}

void LCA_prepare() {
    DFS(1);
    for (int i = 1; i < order.size(); ++i) {
        int v = order[i];
        if (first[v] == 0)
            first[v] = i;
    }
    build(1, 1, order.size() - 1);
}

int LCA(int v1, int v2) {
    v1 = first[v1];
    v2 = first[v2];
    if (v1 > v2)
        swap(v1, v2);
    return minimum(1, 1, order.size() - 1, v1, v2);
}

int main() {
    cin >> n;
    for (int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    LCA_prepare();

    cin >> q;

    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << LCA(x, y) << endl;
    }

    return 0;
}

/*
9 8
1 2
1 3
1 7
2 6
3 4
3 5
4 8
8 9
1
5 9
*/
