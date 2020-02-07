#include <bits/stdc++.h>

using namespace std;

int a, b;

/*
function takes two arguments a and b and returns GCD(a, b). it's iterative version of Euclidean algorithm.
*/
int gcd_iterative(int x, int y) {
    while (y != 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}

/*
function takes two arguments a and b and returns GCD(a, b). it's recursive version of Euclidean algorithm.
*/
int gcd_recursive(int x, int y) {
    if (y == 0) {
        return x;
    }
    return gcd_recursive(y, x % y);
}

/*
function takes two arguments a and b and returns LCM(a, b) using GCD function which can be recursiv or iterativ.
*/
int lcm(int x, int y) {
    return x * y / gcd_iterative(x, y);
}

int main() {
    cin >> a >> b;
    cout << gcd_iterative(a, b) << endl;
    cout << gcd_recursive(a, b) << endl;
    cout << lcm(a, b) << endl;

    return 0;
}