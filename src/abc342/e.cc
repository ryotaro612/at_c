#include <bits/stdc++.h>
#include <limits>
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
struct Rev {
  ll l, d, k, c;
  int a;
  Rev(ll l, ll d, ll k, ll c, int a) : l(l), d(d), k(k), c(c), a(a) {}
};
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<Rev>> g(n);
  vector<ll> res(n, -1);
  res[n - 1] = numeric_limits<ll>::max();
  rep(_, m) {
    ll l, d, k, c, a, b;
    cin >> l >> d >> k >> c >> a >> b;
    g[b - 1].push_back(Rev(l, d, k, c, a - 1));
  }
  priority_queue<pair<ll, int>> que;
  que.push({res[n - 1], n - 1});
  while (que.size()) {
    auto [time, node] = que.top();
    que.pop();
    if (time < res[node])
      continue;
    dbg(node, res[node]);
    for (auto neighbor : g[node]) {
      ll limit = res[node] - neighbor.c;
      if (res[neighbor.a] < limit && neighbor.l <= limit) {
        ll ub = neighbor.k, lb = -1;
        while (ub - lb > 1) {
          ll mid = (ub + lb) / 2ll;
          if (neighbor.l + mid * neighbor.d <= limit) {
            lb = mid;
          } else
            ub = mid;
        }
        res[neighbor.a] = max(res[neighbor.a], neighbor.l + lb * neighbor.d);
        dbg("update", lb, neighbor.a, res[neighbor.a]);
        que.push({res[neighbor.a], neighbor.a});
      }
    }
  }
  rep(i, n - 1) {
    if (res[i] < 0) {
      cout << "Unreachable\n";
    } else
      cout << res[i] << endl;
  }
  return 0;
}
