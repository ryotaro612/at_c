#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

const ll OFFSET = 1000000000ll;

ll drop_nodes(int n, int m, vector<int> &a, vector<int> &b, vector<ll> &c,
              vector<vector<pair<ll, int>>> &g,
              unordered_map<int, unordered_map<int, ll>> &mp) {
    ll ans = 0ll;
    rep(i, m) {
        a[i]--;
        b[i]--;
        if(a[i] == b[i]) {
            if(c[i] > 0)
                ans += c[i];
        } else {
            if(mp[a[i]].find(b[i]) == mp[a[i]].end()) {
                mp[a[i]][b[i]] = mp[b[i]][a[i]] = c[i];
            } else {
                ll cost = mp[a[i]][b[i]];
                if(c[i] < cost) {
                    mp[a[i]][b[i]] = mp[b[i]][a[i]] = c[i];
                    if(cost > 0)
                        ans += cost;
                } else { // c[i] >= cost
                    if(c[i] > 0)
                        ans += c[i];
                }
            }
        }
    }
    for(auto e : mp) {
        for(auto f : e.second) {
            g[e.first].push_back({f.second + OFFSET, f.first});
        }
    }

    return ans;
}

ll solve(int n, int m, vector<int> &a, vector<int> &b, vector<ll> &c) {
    vector<vector<pair<ll, int>>> g(n);
    unordered_map<int, unordered_map<int, ll>> mp;
    ll ans = drop_nodes(n, m, a, b, c, g, mp);

    vector<bool> used(n, false);
    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>,
                   greater<pair<ll, pair<int, int>>>>
        que;
    que.push({0, {0, 0}});
    unordered_map<int, unordered_map<int, bool>> paths;
    while(!que.empty()) {
        pair<int, int> path = que.top().second;
        int node = path.first;
        que.pop();
        if(used[node])
            continue;
        used[node] = true;
        paths[path.first][path.second] = paths[path.second][path.first] = true;
        rep(i, g[node].size()) {
            pair<ll, int> neighbor = g[node][i];
            que.push({neighbor.first, {neighbor.second, node}});
        }
    }
    ll temp = 0ll;
    for(auto e : mp) {
        for(auto f : e.second) {
            if(!paths[e.first][f.first] && mp[e.first][f.first] > 0)
                temp += mp[e.first][f.first];
        }
    }
    return ans + temp / 2ll;
}

#ifdef ONLINE_JUDGE
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    vector<ll> c(m);
    rep(i, m) cin >> a[i] >> b[i] >> c[i];
    cout << solve(n, m, a, b, c) << endl;
    return 0;
}
#endif