#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, t, cnt;
vector<int> G[10001], GT[10001], used(10001), ST[10001], t_out(10001);

void DFS(int v) {
    used[v] = 1;
    for (int x : G[v])
        if (!used[x])
            DFS(x);
    t_out[++t] = v;
}


void DFST(int v) {
    used[v] = 2;
    for (int x : GT[v])
        if (used[x] != 2)
            DFST(x);
    ST[cnt].push_back(v);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        G[x].push_back(y);
        GT[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
        if (!used[i])
            DFS(i);

    for (int i = n; i >= 1; i--) {
        int to = t_out[i];
        if (used[to] != 2) {
            cnt++;
            DFST(to);
        }
    }

    cout << cnt << endl;

    for (int i = 1; i <= cnt; i++) {
        cout << endl;
        for (int j = 0; j < ST[i].size(); j++)
            cout << ST[i][j] << ' ';

    }
    return 0;
}

/*
7 11
1 2
1 5
2 3
2 7
3 7
4 3
4 5
7 6
1 4
3 4
4 2
*/
