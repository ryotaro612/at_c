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
  vector<ll> av(n);
  rep(i, n) { cin >> av[i]; }
  vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
  dp[0][1] = -100000000000ll;
  rep(i, n) {
    dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + av[i] * 2ll);
    dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + av[i]);
    dp[i + 1][0] = max(dp[i][0], dp[i + 1][0]);
    dp[i + 1][1] = max(dp[i][1], dp[i + 1][1]);
  }
  cout << max(dp[n][0], dp[n][1]) << endl;
  return 0;
}
