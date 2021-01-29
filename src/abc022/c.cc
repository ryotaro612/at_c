#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
  3 <= n <= 300;
*/
ll solve(ll n, ll m, vector<ll> u, vector<ll> v, vector<ll> l) {
    const ll inf = 10e12; // 9,223,372,036,854,775,807
    vector<vector<ll>> d(n, vector<ll>(n, inf));
    vector<pair<ll, ll>> neighbors;
    for(ll i = 0ll; i < m; i++) {
        if(u[i] == 1) {
            neighbors.push_back(make_pair(v[i] - 1, l[i]));
        } else if(v[i] == 1) {
            neighbors.push_back(make_pair(u[i] - 1, l[i]));
        } else {
            d[u[i] - 1][v[i] - 1] = l[i];
            d[v[i] - 1][u[i] - 1] = l[i];
        }
    }
    for(ll k = 0ll; k < n; k++) {
        for(ll i = 0ll; i < n; i++) {
            for(ll j = 0ll; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    ll res = inf;
    for(ll i = 0ll; i < (ll)neighbors.size(); i++) {
        ll node_a = neighbors[i].first;
        ll distance_a = neighbors[i].second;
        for(ll j = i + 1; j < (ll)neighbors.size(); j++) {
            ll node_b = neighbors[j].first;
            ll distance_b = neighbors[j].second;
            res = min(distance_a + d[node_a][node_b] + distance_b, res);
        }
    }

    return res == inf ? -1 : res;
}
/*
int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> u(m), v(m), l(m);
    for(int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> l[i];
    }
    cout << solve(n, m, u, v, l) << endl;
}
*/