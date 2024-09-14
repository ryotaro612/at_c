#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#ifndef ONLINE_JUDGE
#define dbg(...)                                                               \
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " " << #__VA_ARGS__       \
       << " = ";                                                               \
  debug_(__VA_ARGS__);
#else
#define dbg(...)
#endif
template <typename Os, typename... Ts>
Os &operator<<(Os &os, const pair<Ts...> &p) {
  return os << "{" << p.first << ", " << p.second << "}";
}
template <typename Os, typename T>
typename enable_if<is_same<Os, ostream>::value, Os &>::type
operator<<(Os &os, const T &v) {
  os << "[";
  string sep = "";
  for (auto &x : v) {
    os << sep << x;
    sep = ", ";
  };
  return os << "]";
}

void debug_() { cerr << "\e[39m" << endl; }

template <typename Head, typename... Tail> void debug_(Head H, Tail... T) {
  cerr << H << " ";
  debug_(T...);
}

void warshall_floyd(vector<vector<ll>> &d) {
  int n = d.size();
  rep(k, n) {
    rep(i, n) {
      rep(j, n) { d[i][j] = min(d[i][j], d[i][k] + d[k][j]); }
    }
  }
  dbg(d);
}
int main() {
  int n, m, q;
  cin >> n >> m;
  vector<vector<ll>> mat(n, vector<ll>(n, 10000000000000ll));
  rep(i, n) mat[i][i] = 0;
  vector<int> uv(m), vv(m);
  vector<ll> tv(m);
  rep(i, m) {
    ll u, v, t;
    cin >> u >> v >> t;
    u--;
    v--;
    uv[i] = u;
    vv[i] = v;
    tv[i] = t;
    mat[u][v] = mat[v][u] = min(mat[v][u], t);
  }
  warshall_floyd(mat);
  cin >> q;
  rep(_, q) {
    int k;
    cin >> k;
    vector<int> bv(k);
    rep(i, k) {
      cin >> bv[i];
      bv[i]--;
    }
    sort(begin(bv), end(bv));

    ll cost = 1e15;
    do {
      rep(pattern, 1 << bv.size()) {
        ll cand = 0;
        int cur = 0;
        rep(j, bv.size()) {
          if (pattern & (1 << j)) {
            cand += mat[cur][uv[bv[j]]] + tv[bv[j]];
            cur = vv[bv[j]];
          } else {
            cand += mat[cur][vv[bv[j]]] + tv[bv[j]];
            cur = uv[bv[j]];
          }
        }
        cand += mat[cur][n - 1];
        cost = min(cost, cand);
      }
    } while (next_permutation(begin(bv), end(bv)));
    cout << cost << endl;
  }
  return 0;
}
