#include <bits/stdc++.h>

using namespace std;

int a, b;

int gcd_iterativ(int x, int y){
    while(y != 0){
        x %= y;
        swap(x, y);
    }
    return x;
}

int gcd_recursiv(int x, int y){
    if(y == 0){
        return x;
    }
    return gcd_recursiv(y, x%y);
}

int lcm(int x, int y){
    return x*y/gcd_iterativ(x, y);
}

int main(){
    cin >> a >> b;
    cout << gcd_iterativ(a, b) << endl;
    cout << gcd_recursiv(a, b) << endl;
    cout << lcm(a, b) << endl;

    return 0;
}