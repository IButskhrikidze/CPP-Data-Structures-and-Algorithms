#include<iostream>

using namespace std;
int n, G[1001][1001], vis[1001], t;

void DFS(int v) {
    vis[v] = 1;
    for (int i = 1; i <= n; i++)
        if (G[v][i] == 1 && vis[i] == 0) {
            DFS(i);
            vis[i] = 1;
            t++;
        }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> G[i][j];
    DFS(1);
    cout << t;

    return 0;
}
