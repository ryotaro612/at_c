#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(int n, int m, vector<ll> a, vector<ll> x, vector<ll> y) {
    vector<vector<int>> edges(n);
    for(int i = 0; i < m; i++)
        edges[x[i] - 1].push_back(y[i] - 1);

    ll inf = 100000000000000ll;
    vector<ll> costs(n, inf);

    for(int i = 0; i < n; i++) {
        if(costs[i] != inf)
            continue;
        queue<int> que;
        for(int j = 0; j < (int)edges[i].size(); j++) {
            int next = edges[i][j];
            if(a[i] < costs[next]) {
                costs[next] = a[i];
                que.push(next);
            }
        }
        while(!que.empty()) {
            int node = que.front();
            que.pop();
            for(int j = 0; j < (int)edges[node].size(); j++) {
                int next = edges[node][j];
                ll cost = min(costs[node], a[node]);
                if(cost < costs[next]) {
                    costs[next] = cost;
                    que.push(next);
                }
            }
        }
    }
    ll res = -inf;
    for(int i = 0; i < n; i++)
        res = max(a[i] - costs[i], res);
    return res;
}

#ifndef _debug
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