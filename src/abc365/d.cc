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
  vector<vector<ll>> dp(n + 1, vector<ll>(3, -100000000000ll));
  const int rock = 0, paper = 1, scissor = 2;
  // 0-> r 1 -> p -> 2
  dp[0][0] = dp[0][1] = dp[0][2] = 0;
  if (s[0] == 'R') {
    dp[0][paper] = 1;
  } else if (s[0] == 'P') {
    dp[0][scissor] = 1;
  } else { // s
    dp[0][rock] = 1;
  }
  for (int i = 1; i < n; i++) {
    if (s[i] == 'R') {
      // p or s
      dp[i][rock] = max(dp[i - 1][paper], dp[i - 1][scissor]);
      dp[i][paper] = 1ll + max(dp[i - 1][rock], dp[i - 1][scissor]);
    } else if (s[i] == 'P') {
      dp[i][scissor] = 1ll + max(dp[i - 1][rock], dp[i - 1][paper]);
      dp[i][paper] = max(dp[i - 1][rock], dp[i - 1][scissor]);
    } else { // scissor
      dp[i][rock] = 1ll + max(dp[i - 1][paper], dp[i - 1][scissor]);
      dp[i][scissor] = max(dp[i - 1][rock], dp[i - 1][paper]);
    }
  }
  cout << max(dp[n-1][rock], max(dp[n-1][scissor], dp[n-1][paper])) << endl;
  return 0;
}
