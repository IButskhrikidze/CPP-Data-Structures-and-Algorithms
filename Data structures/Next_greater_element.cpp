#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> nge(vector<int> a){
    stack<pair<int, int> >s;
    vector<int>ans(a.size());

    for(int i=1;i<a.size();i++){
        if(s.empty()){
            s.push({a[i], i});
            continue;
        }
        while(!s.empty() && s.top().first < a[i]){
            ans[s.top().second] = i;
            s.pop();
        }
        s.push({a[i], i});
    }

    while(!s.empty()){
        ans[s.top().second] = -1;
        s.pop();
    }

    return ans;
}

int main(){
    cin >> n;
    vector<int>a(n+1);

    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    vector<int> ans = nge(a);

    for(int i=1;i<=n;i++){
        cout << ans[i] << ' ';
    }

    return 0;
}