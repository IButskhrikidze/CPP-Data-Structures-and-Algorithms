#include<bits/stdc++.h>

using namespace std;

int cnt, n, q;
string s;

struct Node {
    int ch[26];
    bool end;
    int deg;

    Node() {
        for (int i = 0; i < 26; i++)
            ch[i] = -1;
        end = 0;
        deg = 0;
    }
} a[1000000];

void Add(string s) {
    int k = 0;
    for (int i = 0; i < s.size(); i++)
        if (a[k].ch[s[i] - 'a'] != -1) {
            k = a[k].ch[s[i] - 'a'];
            a[k].deg++;
        } else {
            a[k].ch[s[i] - 'a'] = ++cnt;
            k = cnt;
            a[k].deg++;
        }
    a[cnt].end = true;
}

void Delete(string s) {

}

int Find(string s) {
    int k = 0;
    for (int i = 0; i < s.size(); i++)
        if (a[k].ch[s[i] - 'a'] != -1)
            k = a[k].ch[s[i] - 'a'];
        else
            return false;
    return a[k].deg;
}

int main() {
    cin >> q;
    while (q--) {
        cin >> n >> s;
        switch (n) {
            case 1: {
                Add(s);
                break;
            }
            case 2: {
                Delete(s);
                break;
            }
            default: {
                cout << boolalpha << Find(s) << endl;
                break;
            }
        }
    }

    return 0;
}

