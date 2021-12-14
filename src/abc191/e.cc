#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct edge {
    ll to, cost;
};

const ll INF = 1000000000000000ll;
typedef pair<ll, ll> P;

vector<vector<ll>> dd;

#ifdef ONLINE_JUDGE
int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(m), b(m), c(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
    }

    vector<vector<edge>> g(n, vector<edge>());
    for(int i = 0; i < m; i++)
        g[a[i]].push_back({b[i], c[i]});

    dd.resize(n);

    for(int i = 0; i < n; i++) {
        vector<ll> d(n, INF);
        priority_queue<P, vector<P>, greater<P>> que;
        d[i] = 0ll;
        que.push({0, i});

        while(!que.empty()) {
            P p = que.top();
            que.pop();
            if(d[p.second] < p.first)
                continue;
            for(int j = 0; j < (int)g[p.second].size(); j++) {
                edge e = g[p.second][j];
                if(d[e.to] > d[p.second] + e.cost) {
                    d[e.to] = d[p.second] + e.cost;
                    que.push({d[e.to], e.to});
                }
            }
        }
        dd[i] = vector<ll>(n);
        for(int j = 0; j < n; j++)
            dd[i][j] = d[j];
    }
    vector<ll> ans(n, INF);
    for(int i = 0; i < n; i++) {
        for(edge e : g[i]) {
            ans[i] = min(dd[e.to][i] + e.cost, ans[i]);
        }
    }

    for(int i = 0; i < n; i++)
        if(ans[i] >= INF)
            ans[i] = -1ll;

    for(auto a : ans)
        cout << a << endl;

    return 0;
}
#endif