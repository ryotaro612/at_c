#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const int INF = 147483647; // 2147483647;

ll dfs(int a, vector<int> &d, vector<ll> &paths, vector<vector<int>> &edges) {
    if(paths[a] != -1) {
        return paths[a];
    }
    ll res = 0ll;
    for(int i = 0; i < (int)edges[a].size(); i++) {
        if(d[a] == d[edges[a][i]] + 1) {
            res += dfs(edges[a][i], d, paths, edges);
            res %= MOD;
        }
    }
    paths[a] = res;
    return res;
}

ll solve(int n, int a, int b, int m, vector<int> x, vector<int> y) {
    vector<vector<int>> edges(n);
    for(int i = 0; i < m; i++) {
        edges[x[i] - 1].push_back(y[i] - 1);
        edges[y[i] - 1].push_back(x[i] - 1);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        que;
    vector<int> d(n, INF);
    d[a - 1] = 0;
    que.push(make_pair(0, a - 1));
    while(!que.empty()) {
        pair<int, int> town = que.top();
        que.pop();
        if(d[town.second] < town.first) {
            continue;
        }
        for(int i = 0; i < (int)edges[town.second].size(); i++) {
            int e = edges[town.second][i];
            if(d[e] > d[town.second] + 1) {
                d[e] = d[town.second] + 1;
                que.push(make_pair(d[e], e));
            }
        }
    }
    vector<ll> paths(n, -1);
    paths[a - 1] = 1;
    return dfs(b - 1, d, paths, edges);
}
/*
int main() {
    int n, a, b, m;
    cin >> n >> a >> b >> m;
    vector<int> x(m), y(m);
    for(int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
    }
    cout << solve(n, a, b, m, x, y) << endl;
}
*/