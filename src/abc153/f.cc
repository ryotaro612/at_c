#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ll bom(int n, ll d, ll a, vector<ll> x, vector<ll> h) {
    vector<ll> damage(n, 0ll);
    ll res = 0ll;
    for(int i = 0; i < n; i++) {
        if(i > 0)
            damage[i] += damage[i - 1];
        if(h[i] <= damage[i])
            continue;
        ll count = (h[i] - damage[i] - 1ll) / a + 1ll;
        res += count;
        ll new_damage = count * a;
        damage[i] += new_damage;
        ll edge = x[i] + 2ll * d;
        int edge_index = lower_bound(x.begin(), x.end(), edge) - x.begin();
        if(edge_index < n) {
            if(edge < x[edge_index])
                damage[edge_index] -= new_damage;
            else if(edge_index < n - 1)
                damage[edge_index + 1] -= new_damage;
        }
    }
    return res;
}

ll solve(int n, ll d, ll a, vector<ll> &x, vector<ll> &h) {
    vector<pair<ll, ll>> xh(n);
    rep(i, n) xh[i] = {x[i], h[i]};
    sort(xh.begin(), xh.end());
    rep(i, n) {
        x[i] = xh[i].first;
        h[i] = xh[i].second;
    }
    ll res = bom(n, d, a, x, h);
    reverse(x.begin(), x.end());
    reverse(h.begin(), h.end());
    ll offset = x[0];
    rep(i, n) x[i] = offset - x[i];
    res = min(res, bom(n, d, a, x, h));
    return res;
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    ll d, a;
    cin >> d >> a;
    vector<ll> x(n), h(n);
    rep(i, n) cin >> x[i] >> h[i];
    cout << solve(n, d, a, x, h) << endl;
    return 0;
}
#endif