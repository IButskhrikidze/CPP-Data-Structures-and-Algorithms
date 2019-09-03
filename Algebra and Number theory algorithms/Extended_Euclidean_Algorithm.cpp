#include <bits/stdc++.h>

using namespace std;

int a, b, x, y;

int Extended_GCD(int a, int b, int& x, int& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = Extended_GCD(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b)*y1;;
    return d;
}
int main(){
    cin >> a >> b;
    cout << Extended_GCD(a, b, x, y) << endl;
    cout << x << ' ' << y;

    return 0;
}