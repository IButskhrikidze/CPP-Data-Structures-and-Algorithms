#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n, a[100001], t[400001];

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = a[l];
    } else {
        int m = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m + 1, r);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

ll sum(int v, int l, int r, int tl, int tr) {
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tr + tl) / 2;
    if (r <= tm) {
        return sum(2 * v, l, r, tl, tm);
    }
    if (l > tm) {
        return sum(2 * v + 1, l, r, tm + 1, tr);
    }
    return sum(2 * v, l, tm, tl, tm) + sum(2 * v + 1, tm + 1, r, tm + 1, tr);
}

void Update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        t[v] = val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            Update(v * 2, tl, tm, pos, val);
        else
            Update(v * 2 + 1, tm + 1, tr, pos, val);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    build(1, 1, n);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << sum(1, l, r, 1, n) << ' ';
    }
    return 0;
}
