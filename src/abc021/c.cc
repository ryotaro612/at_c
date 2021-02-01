#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 10e9 + 7ll;
const ll INF = 10e15;

ll solve(ll n, ll a, ll b, ll m, vector<ll> x, vector<ll> y) {
    vector<vector<pair<ll, ll>>> edges(m);
    for(ll i = 0ll; i < m; i++) {
        edges[x[i] - 1].push_back(make_pair(1, y[i] - 1));
        edges[y[i] - 1].push_back(make_pair(1, x[i] - 1));
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
        for(int i = 0ll; i < edges[town.second].size(); i++) {
            pair<ll, ll> e = edges[town.second][i];
            if(d[e.second] > d[town.second] + 1) {
                d[e.second] = d[town.second] + 1;
                que.push(make_pair(d[e.second], e.second));
            }
        }
    }

    return -1ll;
}
/*
int main() {
    ll n, a, b, m;
    cin >> n >> a >> b >> m;
    vector<ll> x(m), y(m);
    for(int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
    }
    cout << solve(n, a, b, m, x, y) << endl;
}
*/