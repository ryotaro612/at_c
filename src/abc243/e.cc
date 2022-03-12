#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

/**
 * nはノードの数
 * node1_v, node2_vは各辺の片方の頂点のベクトル(0オリジン)
 */
vector<vector<long long>> floyd_warshall(int n, vector<int> &node1_v,
                                         vector<int> &node2_v,
                                         vector<long long> &costs,
                                         long long inf = 1ll << 61) {
  vector<vector<long long>> d(n, vector<long long>(n, inf));
  for (int i = 0; i < n; i++)
    d[i][i] = 0ll;
  int m = node1_v.size();
  for (int i = 0; i < m; i++) {
    d[node1_v[i]][node2_v[i]] = d[node2_v[i]][node1_v[i]] = costs[i];
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  return d;
};

int solve(int n, int m, vector<int> &av, vector<int> &bv, vector<ll> &cv) {
  rep(i, m) {
    av[i]--;
    bv[i]--;
  }
  vector<vector<ll>> edges = floyd_warshall(n, av, bv, cv);
  int res = 0;
  rep(i, m) {
    bool required = true;
    if (edges[av[i]][bv[i]] < cv[i]) {
      required = false;
    }
    rep(j, n) {
      if (av[i] != j && bv[i] != j) {
        if (edges[av[i]][bv[i]] == (edges[av[i]][j] + edges[j][bv[i]])) {
          required = false;
        }
      }
    }
    if (!required)
      res++;
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> av(m), bv(m);
  vector<ll> cv(m);
  rep(i, m) cin >> av[i] >> bv[i] >> cv[i];
  cout << solve(n, m, av, bv, cv) << endl;
  return 0;
}
#endif
