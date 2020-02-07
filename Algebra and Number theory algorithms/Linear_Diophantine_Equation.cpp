#include <bits/stdc++.h>

using namespace std;

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


/*
function takes three arguments. a, b, c are coefficients of equation ax+by=c.
function returns pair of some solutions (x, y).
*/
pair<int, int> find_any_solution(int a, int b, int c) {
    int x, y;
    int d = Extended_GCD(abs(a), abs(b), x, y);

    if (c % d != 0) {
        return make_pair(0, 0);
    }

    if (a < 0) {
        x *= -1;
    }
    if (b < 0) {
        y *= -1;
    }

    x *= c / d;
    y *= c / d;

    return make_pair(x, y);
}

/*
function takes seven arguments. a, b, c are parameters of equation.
[lx, rx] and [ly, ry] are range of solutins
*/
vector <pair<int, int>> find_all_solution(int a, int b, int c, int lx, int rx, int ly, int ry) {
    vector <pair<int, int>> ans;
    pair<int, int> any = find_any_solution(a, b, c);
    int lxx = any.first - ((any.first - lx) / b) * b;
    int rxx = any.first - ((any.first - rx) / b) * b;

    ly = any.second + ((ly - any.second) / a) * a;
    ry = any.second + ((ry - any.second) / a) * a;
    int lxxx = (c - b * ly) / a;
    int rxxx = (c - b * ry) / a;
    if (lxxx > rxxx) {
        swap(lxxx, rxxx);
    }
    lxx = max(lxx, lxxx);
    rxx = min(rxx, rxxx);

    if (lxx > rxx) {
        return ans;
    }
    int t = 0;
    int delt = (b < 0 ? 1 : -1);
    while (lxx - b * t <= rxx) {
        ans.push_back({lxx - b * t, (c - a * (lxx - b * t)) / b});
        t += delt;
    }
    return ans;
}

int main() {
    int a, b, c, lx, rx, ly, ry;
    cin >> a >> b >> c >> lx >> rx >> ly >> ry;

    vector <pair<int, int>> ans = find_all_solution(a, b, c, lx, rx, ly, ry);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }
    return 0;
}