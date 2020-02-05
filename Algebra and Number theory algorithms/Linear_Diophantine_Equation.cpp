#include <bits/stdc++.h>

using namespace std;

int a, b, c, x, y, d;

/*
function takes four arguments. a and b are numbers of which GCD we need to find
and x and y are argument references which should be satisfied condition ax+by=gcd(a, b).
function returns GCD of a and b. also, it changes x and y respectively.
*/
int Extended_GCD(int a, int b, int& x, int& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int x_1, y_1;
    int d = Extended_GCD(b, a%b, x_1, y_1);
    x = y_1;
    y = x_1 - (a/b)*y_1;;
    return d;
}


/*
function takes four arguments. a, b, c are coefficients of equation ax+by=c.
num is number of solutions wich we need to find.
function returns vector of pair which contains solutions.
*/
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