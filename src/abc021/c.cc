#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const ll MOD = 10e9 + 7ll;
const ll INF = 10e7;
 
ll dfs(ll a, vector<ll> &d, vector<ll> &paths, vector<vector<ll>> &edges) {
    //cout << "foobar: " << a << " " << paths[a] << endl;
    if(paths[a] != -1) {
        return paths[a];
    }
    ll res = 0ll;
    for(ll i = 0ll; i < (ll)edges[a].size(); i++) {
        //cout << a << " - " << edges[a][i] << " " << d[edges[a][i]] << endl;
        if(d[a] == d[edges[a][i]] + 1) {
            //cout << "dogeee " << endl;
            res += dfs(edges[a][i], d, paths, edges);
            res %= MOD;
        }
    }
    paths[a] = res;
    return res;
}
 
ll solve(ll n, ll a, ll b, ll m, vector<ll> x, vector<ll> y) {
    vector<vector<ll>> edges(n);
    for(ll i = 0ll; i < m; i++) {
        edges[x[i] - 1].push_back(y[i] - 1);
        edges[y[i] - 1].push_back(x[i] - 1);
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
        que;
    vector<ll> d(n, INF);
    d[a - 1] = 0;
    que.push(make_pair(0, a - 1));
    while(!que.empty()) {
        pair<ll, ll> town = que.top();
        que.pop();
        if(d[town.second] < town.first) {
            continue;
        }
        for(ll i = 0ll; i < (ll)edges[town.second].size(); i++) {
            ll e = edges[town.second][i];
            if(d[e] > d[town.second] + 1) {
                d[e] = d[town.second] + 1;
                que.push(make_pair(d[e], e));
            }
        }
    }
    /*
    for(int i = 0; i < n; i++) {
        cout << i << ": " << d[i] << endl;
    }
    cout << " --======= " << endl;
    */
    vector<ll> paths(n, -1);
    paths[a - 1] = 1;
    return dfs(b - 1, d, paths, edges);
}
 
int main() {
    ll n, a, b, m;
    cin >> n >> a >> b >> m;
    vector<ll> x(m), y(m);
    for(int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
    }
    cout << solve(n, a, b, m, x, y) << endl;
}