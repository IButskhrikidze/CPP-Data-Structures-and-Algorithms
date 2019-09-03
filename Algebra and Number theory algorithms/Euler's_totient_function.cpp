#include <bits/stdc++.h>

using namespace std;

long long n;

long long Phi(long long n){
    long long ans = n;
    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            ans -= ans / i;
        }
    }
    if(n > 1)
        ans -= ans / n;
    return ans;
}

int main(){
    cin >> n;
    cout << Phi(n);

    return 0;
}