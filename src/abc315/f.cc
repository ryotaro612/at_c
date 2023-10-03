#include <algorithm>
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
ll my_pow(ll x, ll n) {
  ll res = 1ll;
  while (n) {
    if (n & 1)
      res *= x;
    n >>= 1;
    x *= x;
  }
  return res;
}
ll calc_penalty(int times) {
  if (times == 0)
    return 0;
  return my_pow(2, times - 1);
}

int main() {
  int n;
  cin >> n;
  vector<ll> xv(n), yv(n);

  rep(i, n) cin >> xv[i] >> yv[i];

  ll total = 0;
  for (int i = 1; i < n; i++) {
    total += sqrtl((xv[i] - xv[i - 1]) * (xv[i] - xv[i - 1]) +
                   (yv[i] - yv[i - 1]) * (yv[i] - yv[i - 1])) +
             1ll;
  }
  int mx_penalty = 1;
  while (my_pow(2, mx_penalty) < total)
    mx_penalty++;

  const ll inf = 100000000000000ll;
  vector<vector<ld>> dp(n, vector<ld>(mx_penalty + 1, inf));
  dp[0][0] = 0;

  for (int i = 0; i < n - 1; i++) {
    rep(j, mx_penalty + 1) {
      for (int k = 0; j + k <= mx_penalty && i + 1 + k < n; k++) {
        ll x = xv[i + 1 + k] - xv[i], y = yv[i + 1 + k] - yv[i];
        ll penalty = calc_penalty(j + k) - calc_penalty(j);
        dp[i + 1 + k][j + k] =
            min(dp[i + 1 + k][j + k],
                dp[i][j] + sqrtl(x * x + y * y) + (ld)penalty);
      }
    }
  }

  // rep(i, n) {
  //   rep(j, mx_penalty + 1) {
  //     cout << i << " " << j << " " << fixed << dp[i][j] << endl;
  //   }
  // }
  ld res = inf;
  rep(i, mx_penalty + 1) res = min(res, dp[n - 1][i]);
  cout << fixed << setprecision(12) << res << endl;
  return 0;
}
