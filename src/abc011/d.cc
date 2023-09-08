#include <bits/stdc++.h>
#include <iomanip>
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

ld calc_prob(int n, int m, vector<vector<ld>> &dp) {
  if (n < m)
    return 0;
  if (dp[n][m] >= 0)
    return dp[n][m];
  if (m)
    return dp[n][m] = (ld)(n - m + 1) / (ld)m * calc_prob(n, m - 1, dp);
  if (n)
    return dp[n][m] = (ld)n / (2.0 * (ld)(n - m)) * calc_prob(n - 1, m, dp);
  else
    return dp[n][m] = 1.0;
}
ld sub(int n_step, int n, vector<vector<ld>> &dp) {
  if (n_step > n || ((n - n_step) % 2))
    return 0;
  return calc_prob(n, (n - n_step) / 2, dp);
}

int main() {
  int n;
  ll d, x, y;
  cin >> n >> d >> x >> y;
  if ((x % d != 0 || y % d != 0) || (abs(x) / d + abs(y) / d > n)) {
    cout << 0 << endl;
    return 0;
  }
  int step_x = abs(x) / d, step_y = abs(y) / d;
  ld res = 0;
  vector<vector<ld>> dp(n + 1, vector<ld>(n + 1, -1));
  rep(n_x, n + 1) {
    res +=
        calc_prob(n, n_x, dp) * sub(step_x, n_x, dp) * sub(step_y, n - n_x, dp);
  }
  cout << fixed << setprecision(12) << res << endl;

  return 0;
}
