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
string s;

ll solve(int p, map<int, ll> &dp) {
  int n = s.size();
  if (dp.count(p))
    return dp[p];
  if (p > n)
    return 10000000000ll;
  if (p == (int)s.size()) {
    return dp[p] = 0;
  }
  dp[p] = 1ll + solve(p + 1, dp);
  if (s[p] != '0') {
    return dp[p];
  }
  if (p + 1 < n && s[p + 1] == '0') {
    dp[p] = min(dp[p], 1ll + solve(p + 2, dp));
  }
  return dp[p];
}
int main() {

  cin >> s;
  map<int, ll> dp;

  cout << solve(0, dp) << endl;
  return 0;
}
