#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> G[1000001];
vector<int> ans, deg(1000001);

void Euler(int v) {
    while (G[v].size() > 0) {
        int to = G[v].back();
        G[v].pop_back();
        Euler(to);
    }
    ans.push_back(v);
}

int main() {
    cin >> n >> m;
    for (int u, v, i = 1; i <= m; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        deg[u]++;
        deg[v]--;
    }

    int start = 1, odd_num = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] != 0) {
            odd_num++;
            if (deg[i] > 0) {
                start = i;
            }
        }
    }

    if (odd_num > 2) {
        cout << "No Euler path in this graph";
        return 0;
    }

    Euler(start);
    reverse(ans.begin(), ans.end());

    if (odd_num == 0) {
        cout << "Euler cycle:\n";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << ' ';
        }
    } else {
        cout << "Euler path:\n";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << ' ';
        }
    }

    return 0;
}