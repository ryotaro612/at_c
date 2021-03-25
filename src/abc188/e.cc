#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<ll> par(200000ll);

void init(ll n) {
    for(ll i = 0ll; i < n; i++)
        par[i] = i;
}

ll find(ll v) {
    if(par[v] == v)
        return v;
    return par[v] = find(par[v]);
}

void unite(ll a, ll b) {
    ll par_a = find(a), par_b = find(b);
    if(par_a == par_b)
        return;
    par[par_b] = par_a;
}

bool is_same(ll a, ll b) { return find(a) == find(b); }

ll solve(ll n, ll m, vector<ll> a, vector<ll> x, vector<ll> y) {
    init(n);
    for(ll i = 0ll; i < m; i++)
        unite(x[i] - 1, y[i] - 1);

    vector<vector<ll>> d(n);
    for(ll i = 0ll; i < n; i++)
        d[find(i)].push_back(i);

    for(ll i = 0; i < n; i++)
        sort(d[i].begin(), d[i].end());
    


    ll res = -1000000000000000ll;
    return res;
}

#ifndef _LOCAL
int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), x(m), y(m);
    for(ll i = 0ll; i < n; i++)
        cin >> a[i];
    for(ll i = 0ll; i < m; i++)
        cin >> x[i] >> y[i];
    cout << solve(n, m, a, x, y) << endl;
}
#endif