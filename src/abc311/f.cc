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

const ll MOD = 998244353ll;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  rep(i, n) cin >> grid[i];
  rep(r, n - 1) {
    rep(c, m) {
      if (grid[r][c] == '#') {
        grid[r + 1][c] = '#';
        if (c < m - 1)
          grid[r + 1][c + 1] = '#';
      }
    }
  }
  // dp[i][j]
  vector<vector<ll>> dp(m + 1, vector<ll>(n + 1, 0));
  dp[0][0] = 1ll;
  for (int i = 1; i <= m; i++) {
    vector<ll> acc(n + 1, 0);
    acc[0] = {dp[i - 1][0]};
    for (int j = 1; j <= n; j++) {
      acc[j] = dp[i - 1][j] + acc[j - 1];
      acc[j] %= MOD;
    }
    if (grid[n - 1][i - 1] == '#') {
      dp[i][0] = 0;
    } else {
      dp[i][0] = acc[1];
    }
    // jは積み上げる個数
    rep(j, n + 1) {
      if (j < n && grid[n - 1 - j][i - 1] == '#') {
        dp[i][j] = 0;
      } else {
        if (j < n)
          dp[i][j] = acc[j + 1];
        else
          dp[i][j] = acc[j];
      }
    }
  }
  ll res = 0;
  rep(i, n + 1) {
    res += dp[m][i];
    res %= MOD;
  }
  cout << res << endl;
  return 0;
}
