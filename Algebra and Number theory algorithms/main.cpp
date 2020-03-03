#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n;
vector<bool> e(1e6 + 1, true);
vector<ll> P;

ll mult(ll a, ll b, ll m) {
    if (a > b) {
        swap(a, b);
    }

    if (a == 1 && b == 1) {
        return 1;
    }

    if (b % 2 == 0) {
        ll res = mult(a, b / 2, m);
        return res * 2 % m;
    } else {
        ll res = mult(a, b / 2, m);
        return (res * 2 + a) % m;
    }
}

ll binpow(ll a, ll b, ll m) {
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2, m) % m;
    if (b % 2) {
        return mult(mult(res, res, m), a, m);
    } else {
        return mult(res, res, m);
    }
}

bool probablyPrimeFermat(long long n, int iter = 50) {
    if (n < 4)
        return n == 2 || n == 3;
    srand(time(0));
    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (binpow(a, n - 1, n) != 1)
            return false;
    }
    return true;
}

void prepare() {
    e[1] = false;
    for (int i = 2; i * i <= 1e6; i++) {
        if (e[i]) {
            for (int j = i * i; j <= 1e6; j += i) {
                e[j] = false;
            }
        }
    }

    for (int i = 2; i <= 1e6; i++) {
        if (e[i]) {
            P.push_back(i);
        }
    }
}

int main() {
    cin >> n;
    prepare();
    ll ans = 1;
    for (ll p : P) {
        if (p * p * p > n) {
            break;
        }
        ll cnt = 1;
        while (n % p == 0) {
            cnt++;
            n /= p;
        }
        ans *= cnt;
    }

    ll sqr = sqrt(n);
    if (n != 1 && probablyPrimeFermat(n)) {
        ans *= 2;
    } else if (n != 1 && sqr * sqr == n) {
        ans *= 3;
    } else if (n != 1) {
        ans *= 4;
    }

    cout << ans;

    return 0;
}