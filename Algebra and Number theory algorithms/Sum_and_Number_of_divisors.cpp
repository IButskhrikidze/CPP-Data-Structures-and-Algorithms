#include <bits/stdc++.h>

using namespace std;

long long n;

long long Num_divisors(long long n){
    long long ans = 0;
    for(long long i=1;i*i<=n;i++){
        if(n%i==0){
            if(i==n/i){
                ans++;
            }else{
                ans+=2;
            }
        }
    }
    return ans;
}

long long Sum_divisors(long long n){
    long long ans = 0;
    for(long long i=1;i*i<=n;i++){
        if(n%i==0){
            if(i==n/i){
                ans+=i;
            }else{
                ans+=i+n/i;
            }
        }
    }
    return ans;
}

int main(){
    cin >> n;
    cout << Num_divisors(n) << endl;
    cout << Sum_divisors(n) << endl;

    return 0;
}