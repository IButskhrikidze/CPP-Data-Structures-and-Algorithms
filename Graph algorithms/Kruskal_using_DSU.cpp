#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, w, cnt;

struct Data {
    int x, y, w;
};

bool operator<(Data A, Data B) {
    return A.w < B.w;
}

class DSU {
public:
    int parent[100001], size[100001];

    void make_set(int x) {
        parent[x] = x;
        size[x] = 1;
    }

    int find_set(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find_set(parent[x]);
    }

    void union_sets(int x, int y) {
        x = find_set(x);
        y = find_set(y);
        if (size[x] < size[y])
            swap(x, y);
        if (x != y) {
            parent[y] = x;
            size[x] += size[y];
        }
    }
} A;

vector <Data> G;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> w;
        G.push_back({x, y, w});
    }
    sort(G.begin(), G.end());

    for (int i = 1; i <= n; i++)
        A.make_set(i);

    for (int i = 0; i < G.size(); i++) {
        int x, y, w;
        x = G[i].x;
        y = G[i].y;
        w = G[i].w;
        if (A.find_set(x) != A.find_set(y)) {
            A.union_sets(x, y);
            cnt += w;
        }
    }

    cout << cnt;
    return 0;
}
