#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair<ll, int> P;

ll MOD = 1000000007ll, INF = 1000000000000ll;

void rec(int node, vector<vector<int>> &g, vector<ll> &d, vector<ll> &path) {
    if(path[node] > 0ll)
        return;
    for(int i = 0; i < (int)g[node].size(); i++) {
        int neigh = g[node][i];
        if(d[node] - 1ll != d[neigh])
            continue;
        rec(neigh, g, d, path);
        path[node] += path[neigh];
        path[node] %= MOD;
    }
}

#ifndef _LOCAL
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    queue<P> que;
    vector<ll> d(n, INF);
    d[n - 1] = 0ll;
    que.push({0ll, n - 1});
    while(!que.empty()) {
        P p = que.front();
        que.pop();
        int v = p.second;
        if(d[v] < p.first)
            continue;
        for(int i = 0; i < (int)g[v].size(); i++) {
            int node = g[v][i];
            if(d[node] > d[v] + 1ll) {
                d[node] = d[v] + 1ll;
                que.push({d[node], node});
            }
        }
    }
    /*
for(int i = 0; i < n; i++) {
    cout << i << " -> " << d[i] << endl;
}
    */
    if(d[0] == INF) {
        cout << 0 << endl;
        return 0;
    }
    vector<ll> path(n, 0ll);
    path[n - 1] = 1ll;

    rec(0, g, d, path);
    /*
    for(int i = 0; i < n; i++) {
        cout << i << " -> " << path[i] << endl;
    }
    */
    cout << path[0] << endl;

    return 0;
}
#endif