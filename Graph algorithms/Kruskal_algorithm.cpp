#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, w, cnt, Tree_id[10001];

struct Data {
    int x, y, w;
};

bool operator<(Data A, Data B) {
    return A.w < B.w;
}

vector <Data> g;
vector <pair<int, int>> Tree;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> w;
        g.push_back({x, y, w});
    }

    sort(g.begin(), g.end());

    for (int i = 1; i <= n; i++)
        Tree_id[i] = i;

    for (int i = 0; i < m; i++) {
        int a = g[i].x;
        int b = g[i].y;
        if (Tree_id[a] != Tree_id[b]) {
            cnt += g[i].w;
            Tree.push_back({a, b});
            for (int i = 1; i <= n; i++)
                if (Tree_id[i] == Tree_id[a])
                    Tree_id[i] = Tree_id[b];
        }
    }

    cout << cnt << endl;
    for (int i = 0; i < Tree.size(); i++)
        cout << Tree[i].first << ' ' << Tree[i].second << endl;
    return 0;
}
