#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, a[100001], t[100001];

void Add(int k, int val) {
    while (k < n) {
        t[k] += val;
        k |= (k + 1);
    }
}

int Prefix_sum(int k) {
    int sm = 0;
    while (k >= 0) {
        sm += t[k];
        k = (k & (k + 1)) - 1;
    }
    return sm;
}

int Sum(int l, int r) {
    return Prefix_sum(r) - Prefix_sum(l - 1);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        Add(i, a[i]);
    }

    int q;

    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << Sum(l, r) << endl;
    }

    return 0;
}