#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct Res {
    string yn;
    vector<ll> a, b;
};

ll sum(vector<ll> x) {
    ll res = 0ll;
    for(int i = 0; i < (int)x.size(); i++)
        res += x[i];
    return res;
}

vector<vector<ll>> trans(vector<vector<ll>> m) {
    int n = (int)m.size();
    vector<vector<ll>> t(n, vector<ll>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            t[j][i] = m[i][j];
    }
    return t;
}

vector<ll> sub(ll n, vector<vector<ll>> c) {
    vector<ll> a(n, -1);
    ll base = sum(c[0]);
    ll mini = 0ll;
    vector<ll> offset(n);
    offset[0] = 0ll;
    for(int i = 1; i < n; i++) {
        ll target = sum(c[i]);
        if((target - base) % n != 0ll)
            return a;
        offset[i] = (target - base) / n;
        mini = min(mini, offset[i]);
    }
    a[0] = -mini;
    for(int i = 1; i < n; i++) {
        a[i] = a[0] + offset[i];
    }
    return a;
}

Res solve(ll n, vector<vector<ll>> c) {
    vector<ll> a = sub(n, c);
    for(auto aa: a)
        if(aa < 0)
            return {"No", a, vector<ll>(n, -1)};
    vector<ll> b(n, 0);        
    /*
    for(auto aa: a)
        cout << aa << endl;
        */
    for(int i=0;i<n;i++) {
        b[i] = c[i][i] - a[i];
    }
    for(auto bb: b)
        if(bb < 0)
            return {"No", a, vector<ll>(n, -1)};
    return {"Yes", a, b};
}

#ifndef _LOCAL
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
        for(int i=0;i<n;i++) {
            cout << res.a[i];
            if(i == n-1)
                cout << endl;
            else
                cout << " ";
        }
        for(int i=0;i<n;i++) {
            cout << res.b[i];
            if(i == n-1)
                cout << endl;
            else
                cout << " ";
        }
    }
}
#endif