#include <bits/stdc++.h>

using namespace std;

int a, b, c, x, y, d;

int Extended_GCD(int a, int b, int& x, int& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = Extended_GCD(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b)*y1;
    return d;
}

vector<pair<int, int> > Solve_linear(int a, int b, int c, int num = 1){
    vector<pair<int, int> > ans;
    d = Extended_GCD(abs(a), abs(b), x, y);
    
    if(c%d != 0){
        cout << "No Solution!";
        return ans;
    }

    if(a<0){
        x*=-1;
    }
    if(b<0){
        y*=-1;
    }

    x*=c/d;
    y*=c/d;

    for(int i=0;i<num;i++){
        ans.push_back({y + (a/d)*i, x-(b/d)*i});
    }
    return ans;
}

int main(){
    cin >> a >> b >> c;
    vector<pair<int,int> > ans = Solve_linear(a, b, c, 10);

    for(int i=0;i<ans.size();i++){
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }

    return 0;
}