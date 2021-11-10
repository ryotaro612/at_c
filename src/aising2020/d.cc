#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ll popcount(string &s) {
    ll res = 0ll;
    for(auto c : s)
        if(c == '1')
            res++;
    return res;
}
vector<ll> calc_f() {
    int mx = 200001;
    vector<ll> v(mx, 0ll);
    for(int i = 1; i < mx; i++) {
        v[i] = v[i % __builtin_popcount(i)] + 1ll;
    }
    return v;
}

vector<vector<ll>> build_cache(ll n, ll n_pops) {
    vector<vector<ll>> res(2, vector<ll>(n));
    ll div_plus = 1ll, div_minus = 1ll;
    rep(i, n) {
        div_minus %= (n_pops - 1ll);
        div_plus %= (n_pops + 1ll);
        res[0][i] = div_minus;
        res[1][i] = div_plus;
        div_plus *= 2ll;
        div_minus *= 2ll;
    }
    reverse(res[0].begin(), res[0].end());
    reverse(res[1].begin(), res[1].end());
    return res;
}
vector<ll> solve(ll n, string &s) {
    ll n_pops = popcount(s);
    if(n_pops == 0ll)
        return vector<ll>(n, 1ll);
    if(n_pops == 1ll) {
        vector<ll> res(n);
        rep(i, n) {
            if(s[i] == '1')
                res[i] = 0ll;
            else { // s[i] == '0'
                if(s[n - 1] == '1' || i == n - 1) {
                    // unreachable
                    res[i] = 2ll;
                } else {
                    res[i] = 1ll;
                }
            }
        }
        return res;
    }
    vector<vector<ll>> cache = build_cache(n, n_pops);
    ll sum_plus = 0ll, sum_minus = 0ll;
    rep(i, n) {
        if(s[i] == '1') {
            sum_minus += (ll)cache[0][i];
            sum_plus += (ll)cache[1][i];
        }
    }
    vector<ll> f = calc_f();
    vector<ll> res(n);
    rep(i, n) {
        ll v;
        if(s[i] == '1') {
            v = (sum_minus - cache[0][i] + n_pops - 1ll) % (n_pops - 1ll);
        } else {
            v = (sum_plus + cache[1][i] + n_pops + 1ll) % (n_pops + 1ll);
        }
        res[i] = f[v] + 1ll;
    }
    return res;
}

#ifndef _debug
int main() {
    ll n;
    cin >> n;
    string x;
    cin >> x;
    vector<ll> res = solve(n, x);
    for(auto e : res)
        cout << e << endl;
    return 0;
}
#endif
