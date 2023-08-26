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
  vector<ll> xv(n), yv(n), zv(n);
  ll z_all = 0;
  rep(i, n) {
    cin >> xv[i] >> yv[i] >> zv[i];
    z_all += zv[i];
  }

  vector<vector<ll>> dp(n + 1, vector<ll>(z_all + 1, 1000000000000ll));
  dp[0][0] = 0ll;
  rep(i, n) {
    rep(j, z_all + 1) {
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      if (xv[i] > yv[i]) {
        if (j + zv[i] <= z_all) {
          dp[i + 1][j + zv[i]] = min(dp[i + 1][j + zv[i]], dp[i][j]);
        }
      } else {
        ll remain = ((xv[i] + yv[i]) + 1ll) / 2ll - xv[i];
        if (j + zv[i] <= z_all)
          dp[i + 1][j + zv[i]] = min(dp[i + 1][j + zv[i]], dp[i][j] + remain);
      }
    }
  }
  ll res = 10000000000000ll;
  for (int i = z_all / 2ll + 1ll; i <= z_all; i++) {
    res = min(dp[n][i], res);
  }
  dbg(dp);
  cout << res << endl;

  return 0;
}
