#include <bits/stdc++.h>

using namespace std;

long long n;

vector<bool> Sieve(long long n){
    vector<bool> ans(n+1, true);
    ans[0] = ans[1] = false;
    for(long long i=2;i*i<=n;i++){
        if(ans[i]){
            for(long long j=i*i;j<=n;j+=i){
                ans[j] = false;
            }
        }
    }

    return ans;
}

int main(){
    cin >> n;
    vector<bool> is_prime = Sieve(n);

    for(int i=1;i<=n;i++){
        if(is_prime[i]){
            cout << i << ' ';
        }
    }

    return 0;
}