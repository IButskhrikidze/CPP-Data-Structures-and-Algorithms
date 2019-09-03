#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, m, a[1001][1001], t[1001][1001];

void Add(int x, int y, int val) {
    for(int i=x; i < n; i |= (i+1)){
        for(int j=y; j < m; j |= (j+1)) {
            t[i][j] += val;
        }
    }
}

int Prefix_sum(int x, int y) {
    int sm = 0;
    for(int i = x; i >= 0; i = (i&(i+1)) - 1){
        for(int j = y; j >= 0; j = (j&(j+1)) - 1) {
            sm += t[i][j];
        }
    }
    return sm;
}

//top left and bottom right coordinate
int Sum(int x1, int y1, int x2, int y2) {
    return Prefix_sum(x2, y2) - Prefix_sum(x2, y1 - 1) - Prefix_sum(x1 - 1, y2) + Prefix_sum(x1 - 1, y1 - 1);
}

int main() {
    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
            Add(i, j, a[i][j]);
        }
    }

    int q;

    cin >> q;

    while (q--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << Sum(x1, y1, x2, y2) << endl;
    }

    return 0;
}