#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

static const ll INF = 1000000000000000ll;

void update_if_less(map<ll, ll> &mp, ll pos, ll v) {
    if(mp.find(pos) != mp.end())
        mp[pos] = min(v, mp[pos]);
    else
        mp[pos] = v;
}

ll solve(ll n, vector<ll> x, vector<ll> c) {
    vector<ll> edge_min(n + 1ll, INF), edge_max(n + 1ll, -INF);
    set<ll> balls;
    for(ll i = 0ll; i < n; i++) {
        edge_min[c[i]] = min(x[i], edge_min[c[i]]);
        edge_max[c[i]] = max(x[i], edge_max[c[i]]);
        balls.insert(c[i]);
    }
    vector<ll> ball_vec(balls.begin(), balls.end());
    sort(ball_vec.begin(), ball_vec.end());
    map<ll, ll> mp;
    mp[0ll] = 0ll;
    for(auto ball : ball_vec) {
        map<ll, ll> next_mp;
        for(auto pair : mp) {
            if(edge_max[ball] <= pair.first) {
                ll pos = edge_min[ball];
                ll cost = abs(pair.first - pos) + pair.second;
                update_if_less(next_mp, pos, cost);
            } else if(pair.first <= edge_min[ball]) {
                ll pos = edge_max[ball];
                ll cost = abs(pos - pair.first) + pair.second;
                update_if_less(next_mp, pos, cost);
            } else {
                ll pos = edge_min[ball];
                ll cost = abs(edge_max[ball] - pair.first) +
                          abs(edge_max[ball] - pos) + pair.second;
                update_if_less(next_mp, pos, cost);
                pos = edge_max[ball];
                cost = abs(pair.first - edge_min[ball]) +
                       abs(pos - edge_min[ball]) + pair.second;
                update_if_less(next_mp, pos, cost);
            }
        }
        mp = next_mp;
    }
    ll res = INF;
    for(auto pair : mp)
        res = min(abs(pair.first) + pair.second, res);

    return res;
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<ll> x(n), c(n);
    for(int i = 0; i < n; i++)
        cin >> x[i] >> c[i];
    cout << solve(n, x, c) << endl;
}
#endif