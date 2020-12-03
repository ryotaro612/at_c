#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge {
    ll to, cost;
};
ll INF = 1223372036854775807;
vector<ll> solve(ll n, vector<ll> a, vector<ll> b, vector<ll> c, ll q, ll k,
                 vector<ll> x, vector<ll> y) {
    vector<vector<edge>> edges(n, vector<edge>());

    vector<ll> d(n, INF);

    for(int i = 0; i < n - 1; i++) {
        edges[a[i] - 1].push_back(edge({b[i] - 1, c[i]}));
        edges[b[i] - 1].push_back(edge({a[i] - 1, c[i]}));
    }
    d[k - 1] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
        que;
    que.push(make_pair(0, k - 1));
    while(!que.empty()) {
        pair<ll, ll> p = que.top();
        que.pop();
        if(d[p.second] < p.first)
            continue;
        for(int i = 0; i < (int)edges[p.second].size(); i++) {
            edge e = edges[p.second][i];
            if(d[e.to] > d[p.second] + e.cost) {
                d[e.to] = d[p.second] + e.cost;
                que.push(make_pair(d[e.to], e.to));
            }
        }
    }
    vector<ll> res(q);
    for(int i = 0; i < q; i++) {
        res[i] = d[x[i] - 1] + d[y[i] - 1];
    }
    return res;
}
/*
int main() {
    ll n, q, k;
    cin >> n;
    vector<ll> a(n - 1), b(n - 1), c(n - 1);
    for(ll i = 0; i < n - 1; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    cin >> q >> k;
    vector<ll> x(q), y(q);
    for(ll i = 0; i < q; i++) {
        cin >> x[i] >> y[i];
    }
    vector<ll> res = solve(n, a, b, c, q, k, x, y);
    for(auto r : res) {
        cout << r << endl;
    }
}
*/