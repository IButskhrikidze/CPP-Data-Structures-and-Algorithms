#include <bits/stdc++.h>

using namespace std;

const double inf = 1e9;

int n;
vector<pair<double, double> >Points;

double cost(int i, int j){
    return hypot(Points[i].first-Points[j].first, Points[i].second-Points[j].second);
}

int main() {
    cin >> n;
    Points.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> Points[i].first >> Points[i].second;
    }

    double dp[n][1 << n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = inf;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][1 ^ (1 << j)] = cost(0,i);
        }
    }

    for (int i = 3; i <= n; i++) {
        for (int j = 1; j < (1 << n); j++) {
            if (__builtin_popcount(j) == i && (1 & j)) {
                for (int k = 1; k < n; k++) {
                    if (j & (1 << k)) {
                        for (int p = 1; p < n; p++) {
                            if (p != k && (j & (1 << p))) {
                                int mask = j ^(1 << k);
                                dp[k][j] = min(dp[p][mask] + cost(k,p), dp[k][j]);
                            }
                        }

                    }
                }
            }
        }
    }

    double ans = inf;

    for (int i = 1; i < n; i++) {
        ans = min(ans, dp[i][(1 << n) - 1] + cost(i,0));
    }

    cout << ans;

    return 0;
}