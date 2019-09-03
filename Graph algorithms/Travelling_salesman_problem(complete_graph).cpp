#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int n, ans = 1e9;
vector <vector<int>> cost;

int main() {
    cin >> n;
    cost.resize(n);

    for (int i = 0; i < n; i++) {
        cost[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    int dp[n][1 << n];

    for(int i=0;i<n;i++){
        for(int j=0;j<(1<<n);j++){
            dp[i][j] = inf;
        }
    }
    for (int i = 1; i < n; i++) {
        for(int j=1; j < n; j++) {
            dp[i][1 ^ (1 << j)] = cost[0][i];
        }
    }

    for (int i = 3; i <= n; i++) {
        for (int j = 1; j < (1 << n); j++) {
            if (__builtin_popcount(j) == i && (1 & j)) {
                for (int k = 1; k < n; k++) {
                    if (j & (1 << k)) {
                        for (int p = 1; p < n; p++) {
                            if (p != k && (j & (1 << p))) {
                                int mask = j ^ (1 << k);
                                dp[k][j] = min(dp[p][mask]+cost[k][p], dp[k][j]);
                            }
                        }

                    }
                }
            }
        }
    }

    for(int i=1;i<n;i++){
        ans = min(ans, dp[i][(1<<n)-1] + cost[i][0]);
    }

    cout << ans;

    return 0;
}
