#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct edge {
    ll to, t, k;
};
typedef pair<ll, ll> P;

static const ll INF = 1000000000000000ll;

ll calc_time(ll base, ll k) {
    if(base == 0ll)
        return 0ll;
    if(base < k)
        return k;
    // base >= k
    if(base % k == 0ll)
        return base / k * k;

    return base / k * k + k;
}

ll solve(int n, int m, int x, int y, vector<ll> a, vector<ll> b, vector<ll> t,
         vector<ll> k) {
    x--;
    y--;
    vector<vector<edge>> g(n);
    for(int i = 0; i < m; i++) {
        g[a[i] - 1].push_back({b[i] - 1, t[i], k[i]});
        g[b[i] - 1].push_back({a[i] - 1, t[i], k[i]});
    }
    vector<ll> d(n, INF);
    d[x] = 0ll;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0ll, x));
    while(!que.empty()) {
        P p = que.top();
        que.pop();
        ll v = p.second;
        if(d[v] < p.first)
            continue;
        for(int i = 0; i < (int)g[v].size(); i++) {
            edge e = g[v][i];
            ll cost = calc_time(d[v], e.k) + e.t;
            if(d[e.to] > cost) {
                d[e.to] = cost;
                //cout << "update: " << e.to + 1 << " -> " << d[e.to] << endl;
                que.push(P(d[e.to], e.to));
            }
        }
    }

    return d[y] == INF ? -1 : d[y];
}

#ifndef _debug
int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<ll> a(m), b(m), t(m), k(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> t[i] >> k[i];
    }
    cout << solve(n, m, x, y, a, b, t, k) << endl;
    return 0;
}
#endif