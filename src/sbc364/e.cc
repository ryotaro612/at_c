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
  ll n, x, y;
  cin >> n >> x >> y;
  vector<ll> av(n), bv(n);
  rep(i, n) { cin >> av[i] >> bv[i]; }
  vector<vector<vector<ll>>> dp(
      n + 1, vector<vector<ll>>(n + 1, vector<ll>(x + 1ll, y + 1)));
  // 番号 個数 甘さ
  dp[0][0][0] = 0;
  rep(i, n) {
    rep(j, n) {
      rep(k, x + 1) {
        if (k + av[i] <= x) {
          dp[i + 1][j + 1][k + av[i]] =
              min(dp[i + 1][j + 1][k + av[i]], dp[i][j][k] + bv[i]);
        }
        dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
      }
    }
  }
  int res = 0;

  rep(j, n + 1) {
    rep(k, x + 1) {
      if (dp[n][j][k] <= y)
        res = max(j, res);
    }
  }
  cout << min((int)n, res + 1) << endl;
  return 0;
}
