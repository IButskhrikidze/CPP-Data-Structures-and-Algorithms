#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, w;

    bool operator<(const Edge A) const {
        if (A.w == w) {
            if (A.u == u) {
                return v < A.v;
            } else {
                return u < A.u;
            }
        } else {
            return w < A.w;
        }
    }
};

int n, m, ans;
set<Edge> st;
vector<int> used;
vector<Edge> mst;
vector<vector<pair<int, int> > > G;

int main() {
    cin >> n >> m;
    G.resize(n + 1);
    used.resize(n + 1);
    for (int u, v, w, i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    used[1] = 1;
    for (int i = 0; i < G[1].size(); i++) {
        st.insert({1, G[1][i].first, G[1][i].second});
    }

    for (int i = 1; i < n; i++) {
        while (used[st.begin()->v] == 1) {
            st.erase(st.begin());
        }

        Edge top = *st.begin();
        st.erase(st.begin());

        mst.push_back(top);

        ans += top.w;
        used[top.v] = 1;

        for (int i = 0; i < G[top.v].size(); i++) {
            if (used[G[top.v][i].first] == 0) {
                st.insert({top.v, G[top.v][i].first, G[top.v][i].second});
            }
        }
    }

    cout << "MST weight is: " << ans << endl;
    for(int i=0;i<mst.size();i++){
        cout << mst[i].u << ' ' << mst[i].v << ' ' << mst[i].w << endl;
    }

    return 0;
}
