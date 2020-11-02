#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(int i = 0; (i) < int(n); ++(i))

const ll MX = 200000000;
struct edge {
    ll to;
    ll cost;
};

bool dfs(ll from, vector<vector<edge>> &edges, vector<ll> &d) {
    for(edge e : edges[from]) {
        if(d[e.to] == MX) {
            d[e.to] = d[from] + e.cost;
            if(!dfs(e.to, edges, d)) {
                return false;
            }
        } else if(d[e.to] != d[from] + e.cost) {
            return false;
        }
    }
    return true;
}

string solve(ll n, ll m, vector<ll> l, vector<ll> r, vector<ll> d) {
    if(m == 0) {
        return "Yes";
    }
    vector<vector<edge>> edges(n, vector<edge>());
    for(ll i = 0; i < m; i++) {
        edges[l[i] - 1].push_back({r[i] - 1, d[i]});
        edges[r[i] - 1].push_back({l[i] - 1, -d[i]});
    }
    vector<ll> dist(n, MX);
    for(ll i = 0; i < n; i++) {
        if(dist[i] == MX) {
            dist[i] = 0;
            if(!dfs(i, edges, dist)) {
                return "No";
            }
        }
    }

    return "Yes";
}
/*
int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> l(m), r(m), d(m);
  for (ll i = 0; i < m; i++) {
    cin >> l[i] >> r[i] >> d[i];
  }
  cout << solve(n, m, l, r, d);
}
*/