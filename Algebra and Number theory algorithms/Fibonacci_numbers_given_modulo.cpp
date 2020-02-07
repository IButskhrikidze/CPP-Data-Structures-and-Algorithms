#include <bits/stdc++.h>

#define ll long long

using namespace std;

/*
multiplication of two square matrix. takes two 2D vectors and returns its matrix product modulo mod
*/
vector<vector<ll> > product(vector<vector<ll> > A, vector<vector<ll> > B, ll mod) {
    int n = A.size();
    vector<vector<ll> > ans(n);
    for (int i = 0; i < n; i++) {
        ans[i].resize(n);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ans[i][j] += A[i][k] * B[k][j];
                ans[i][j] %= mod;
            }
        }
    }
    return ans;
}

/*
power of matrix modulo mod. takes 2D matrix A, degree n, and modulo mod. returns A^n modulo mod;
*/
vector<vector<ll> > binpow(vector<vector<ll> > A, ll n, ll mod) {
    if (n == 1) {
        return A;
    }

    if (n % 2 == 0) {
        vector<vector<ll> > ans = binpow(A, n / 2, mod);
        return product(ans, ans, mod);
    }

    return product(A, binpow(A, n - 1, mod), mod);
}

int main() {
    ll n, mod;
    cin >> n >> mod;

    //initial 2D matrix for calculation finonacci numbers
    vector<vector<ll> > F = {{1, 1},
                             {1, 0}};
    F = binpow(F, n, mod);

    cout << F[0][1];

    return 0;
}
