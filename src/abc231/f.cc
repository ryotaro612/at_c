#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

void compress(vector<ll> &v) {
    set<ll> a_set(v.begin(), v.end());
    ll count = 1ll;
    unordered_map<ll, ll> mp;
    for(auto e : a_set) {
        mp[e] = count++;
    }
    for(auto &e : v)
        e = mp[e];
}

ll sum(int i, vector<ll> &bit) {
    ll s = 0;
    while(i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

void add(int i, ll x, vector<ll> &bit) {
    while(i <= (int)bit.size() - 1) {
        bit[i] += x;
        i += i & -i;
    }
}

ll solve(int n, vector<ll> &av, vector<ll> &bv) {
    compress(av);
    compress(bv);
    ll mx = 0;
    for(auto e : bv)
        mx = max(mx, e);
    vector<ll> bit(mx + 1, 0);
    map<ll, vector<ll>> mp;
    rep(i, n) { mp[av[i]].push_back(bv[i]); }
    ll res = 0ll;
    for(auto p : mp) {
        for(auto b : p.second) {
            add(b, 1, bit);
        }
        for(auto b : p.second) {
            ll temp = sum(mx, bit) - sum(b - 1, bit);
            res += temp;
        }
    }

    return res;
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<ll> av(n), bv(n);
    rep(i, n) cin >> av[i];
    rep(i, n) cin >> bv[i];
    cout << solve(n, av, bv) << endl;
    return 0;
}
#endif