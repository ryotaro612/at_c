#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct chokudai {
    ll x, y, h;
};

chokudai solve(int n, vector<ll> xv, vector<ll> yv, vector<ll> hv) {
    int m_i = 0;
    for(int i = 0; i < n; i++) {
        if(hv[m_i] < hv[i])
            m_i = i;
    }
    for(ll x = 0ll; x <= 100ll; x++) {
        for(ll y = 0ll; y <= 100ll; y++) {
            ll h = hv[m_i] + abs(x - xv[m_i]) + abs(y - yv[m_i]);
            bool ok = true;
            for(int i = 0; i < n; i++) {
                if(hv[i] != max(h - abs(x - xv[i]) - abs(y - yv[i]), 0ll)) {
                    ok = false;
                    break;
                }
            }
            if(ok)
                return {x, y, h};
        }
    }
    return {0, 0, 0};
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n), h(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> h[i];
    }
    chokudai res = solve(n, x, y, h);
    cout << res.x << " " << res.y << " " << res.h << endl;
    return 0;
}
#endif