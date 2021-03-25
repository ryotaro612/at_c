#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct P {
    ll to, cost;
};

ll solve(int n, int m, vector<ll> a, vector<ll> x, vector<ll> y) {
    vector<vector<ll>> edges(n);
    for(int i = 0; i < m; i++)
        edges[x[i] - 1ll].push_back(y[i] - 1ll);

    queue<P> que;
    for(int i = 0; i < (int)edges[0].size(); i++)
        que.push({edges[0][i], a[0]});

    ll res = a[y[0] - 1] - a[x[0] - 1];
    while(!que.empty()) {
        P p = que.front();
        que.pop();
        res = max(a[p.to] - p.cost, res);
        for(int i = 0; i < (int)edges[p.to].size(); i++) {
            que.push({edges[p.to][i], min(a[p.to], p.cost)});
        }
    }
    return res;
}

#ifndef _LOCAL
int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), x(m), y(m);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> x[i] >> y[i];
    cout << solve(n, m, a, x, y) << endl;
}
#endif