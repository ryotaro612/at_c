#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct Res {
    string yn;
    vector<ll> a, b;
};

Res solve(ll n, vector<vector<ll>> c) {
    ll mini = c[0][0];
    for(int i = 1; i < n; i++) {
        mini = min(mini, c[i][0]);
    }
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) {
        a[i] = c[i][0] - mini;
        if(a[i] < 0)
            return {"No", a, b};
    }
    for(int i = 0; i < n; i++) {
        b[i] = c[0][i] - a[0];
        if(b[i] < 0)
            return {"No", a, b};
        for(int j = 1; j < n; j++) {
            if(b[i] != c[j][i] - a[j])
                return {"No", a, b};
        }
    }
    return {"Yes", a, b};
}

#ifndef _debug
int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> c(n, vector<ll>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> c[i][j];
    Res res = solve(n, c);
    cout << res.yn << endl;
    if(res.yn == "Yes") {
        for(int i = 0; i < n; i++) {
            cout << res.a[i];
            if(i == n - 1)
                cout << endl;
            else
                cout << " ";
        }
        for(int i = 0; i < n; i++) {
            cout << res.b[i];
            if(i == n - 1)
                cout << endl;
            else
                cout << " ";
        }
    }
}
#endif