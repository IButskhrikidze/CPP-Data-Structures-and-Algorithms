#include <bits/stdc++.h>

using namespace std;

int a, b, x, y;

/*
function takes four arguments. a and b are numbers of which GCD we need to find
and x and y are argument references which should be satisfied condition ax+by=gcd(a, b).
function returns GCD of a and b. also, it changes x and y respectively.
*/
int Extended_GCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x_1, y_1;
    int d = Extended_GCD(b, a % b, x_1, y_1);
    x = y_1;
    y = x_1 - (a / b) * y_1;;
    return d;
}

int main() {
    cin >> a >> b;
    cout << Extended_GCD(a, b, x, y) << endl;
    cout << x << ' ' << y;

    return 0;
}