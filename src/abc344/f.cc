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

int main() {
  int n;
  cin >> n;
  vector<vector<ll>> pm(n, vector<ll>(n)), rm(n, vector<ll>(n - 1)),
      dm(n - 1, vector<ll>(n));
  vector<ll> pv;
  rep(r, n) {
    rep(c, n) {
      cin >> pm[r][c];
      pv.push_back(pm[r][c]);
    }
  }
  rep(r, n) {
    rep(c, n - 1) { cin >> rm[r][c]; }
  }
  rep(r, n - 1) {
    rep(c, n) { cin >> dm[r][c]; }
  }
  const ll inf = 1000000000000ll;

  vector<vector<pair<ll, ll>>> dp(n, vector<pair<ll, ll>>(n, {inf, 0}));
  dp[0][0] = {0, 0};
  rep(r, n) {
    rep(c, n) {
      vector<vector<ll>> dist(r + 1, vector<ll>(c + 1, inf));
      dist[r][c] = 0;
      for (int y = r; y >= 0; y--) {
        for (int x = c; x >= 0; x--) {
          if (y < r) {
            dist[y][x] = min(dist[y][x], dm[y][x] + dist[y + 1][x]);
          }
          if (x < c) {
            dist[y][x] = min(dist[y][x], rm[y][x] + dist[y][x + 1]);
          }
          ll cost = max(0ll, dist[y][x] - dp[y][x].second + pm[y][x] - 1ll) /
                    pm[y][x];
          ll t = dp[y][x].first + cost + r - y + c - x;
          ll m = dp[y][x].second + cost * pm[y][x] - dist[y][x];
          if (t < dp[r][c].first ||
              (t == dp[r][c].first && m > dp[r][c].second))
            dp[r][c] = {t, m};
        }
      }
    }
  }
  cout << dp[n - 1][n - 1].first << endl;
  return 0;
}
