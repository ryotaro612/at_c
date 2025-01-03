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
  vector<int> hv(n);
  rep(i, n) cin >> hv[i];
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1));

  rep(i, n) {
    for (int j = i + 1; j < n; j++) {
      if (hv[i] == hv[j]) {
        dp[j][j - i] = max(dp[j][j - i], dp[i][j - i] + 1);
      }
    }
  }

  int res = 0;
  for (auto aa : dp) {
    for (auto a : aa)
      res = max(a, res);
  }
  cout << res << endl;

  return 0;
}
