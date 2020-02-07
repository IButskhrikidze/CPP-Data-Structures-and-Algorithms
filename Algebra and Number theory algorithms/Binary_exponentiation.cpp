#include <bits/stdc++.h>

using namespace std;


/*
function takes two arguments a and n. it will calculate and returns a^n. it's recursive version.
it is possible to modified function so that it will return a^n modulo some m.
*/
long long binpow_recursive(long long a, long long n) {
    if (n == 0)
        return 1;
    long long res = binpow_recursive(a, n / 2);
    if (n % 2)
        return res * res * a;
    else
        return res * res;
}

/*
function takes two arguments a and n. it will calculate and returns a^n. it's iterative version.
it is possible to modified function so that it will return a^n modulo some m.
*/
long long binpow_iterative(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

int main() {
    long long a, n;
    cin >> a >> n;
    cout << binpow_recursive(a, n) << endl;
    cout << binpow_iterative(a, n) << endl;

    return 0;
}