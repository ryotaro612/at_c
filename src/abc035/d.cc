#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct edge {
    int to;
    ll cost;
};
typedef pair<int, int> P;

ll const INF = 10000000000000;

vector<ll> djkstra(vector<vector<edge>> edges) {
    priority_queue<P, vector<P>, greater<P>> que;
    vector<ll> d((int)edges.size(), INF);
    d[0] = 0;
    que.push(P(0, 0));
    while(!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if(d[v] < p.first)
            continue;
        for(int i = 0; i < (int)edges[v].size(); i++) {
            edge e = edges[v][i];
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
    return d;
}

ll solve(int n, int m, ll t, vector<int> a, vector<int> av, vector<int> bv,
         vector<int> cv) {
    vector<vector<edge>> forward(n), backward(n);
    for(int i = 0; i < m; i++) {
        forward[av[i] - 1].push_back({bv[i] - 1, cv[i]});
        backward[bv[i] - 1].push_back({av[i] - 1, cv[i]});
    }

    vector<ll> cost_forward = djkstra(forward);
    vector<ll> cost_backward = djkstra(backward);
    ll res = 0;
    for(int i = 0; i < n; i++) {
        res = max(res, a[i] * (t - cost_forward[i] - cost_backward[i]));
    }

    return res;
}
/*
int main() {
    int n, m;
    ll t;
    cin >> n >> m >> t;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> av(m), bv(m), cv(m);
    for(int i = 0; i < m; i++) {
        cin >> av[i] >> bv[i] >> cv[i];
    }
    cout << solve(n, m, t, a, av, bv, cv) << endl;
}
*/