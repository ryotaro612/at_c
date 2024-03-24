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
  string s;
  cin >> n >> s;
  vector<ll> cv(n);
  rep(i, n) cin >> cv[i];

  vector<vector<vector<ll>>> dp(
      n, vector<vector<ll>>(2, vector<ll>(2, 1'000'000'000'000'000'000ll)));
  if (s[0] == '0') {
    dp[0][0][0] = 0;
    dp[0][1][0] = cv[0];
  } else {
    dp[0][0][0] = cv[0];
    dp[0][1][0] = 0;
  }

  for (int i = 1; i < n; i++) {
    if (s[i] == '0') {
      dp[i][0][0] = dp[i - 1][1][0];
      dp[i][0][1] = min(dp[i - 1][1][1], dp[i - 1][0][0]);
      dp[i][1][0] = cv[i] + dp[i - 1][0][0];
      dp[i][1][1] = cv[i] + min(dp[i - 1][0][1], dp[i - 1][1][0]);
    } else { // s[i]==1
      dp[i][0][0] = cv[i] + dp[i - 1][1][0];
      dp[i][0][1] = cv[i] + min(dp[i - 1][0][0], dp[i - 1][1][1]);
      dp[i][1][0] = dp[i - 1][0][0];
      dp[i][1][1] = min(dp[i - 1][1][0], dp[i - 1][0][1]);
    }
  }

  cout << min(dp[n - 1][0][1], dp[n - 1][1][1]) << endl;

  return 0;
}
