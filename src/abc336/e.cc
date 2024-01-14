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
  string s;
  cin >> s;
  ll res = 0;
  int n = s.size();
  for (ll ketawa = 1; ketawa <= 9 * 15; ketawa++) {
    vector<vector<vector<vector<ll>>>> dp(
        n + 1, vector<vector<vector<ll>>>(
                   2, vector<vector<ll>>(ketawa + 1, vector<ll>(ketawa, 0))));
    dp[0][1][0][0] = 1;
    for (int i = 1; i <= n; i++) {
      ll d = s[i - 1] - '0';
      ll shift = 1;
      rep(j, n - i) shift *= 10ll;

      for (int cost = 0; cost <= ketawa; cost++) {
        for (int remain = 0; remain < ketawa; remain++) {
          if (cost + d <= ketawa) {
            dp[i][1][cost + d][(remain + d * shift) % ketawa] +=
                dp[i - 1][1][cost][remain];
          }
          for (ll j = 0; j < d && cost + j <= ketawa; j++) {
            dp[i][0][cost + j][(remain + j * shift) % ketawa] +=
                dp[i - 1][1][cost][remain];
          }
          for (ll j = 0; j < 10 && cost + j <= ketawa; j++) {
            dp[i][0][cost + j][(remain + j * shift) % ketawa] +=
                dp[i - 1][0][cost][remain];
          }
        }
      }
    }
    res += dp[n][1][ketawa][0] + dp[n][0][ketawa][0];
  }
  cout << res << endl;
  return 0;
}
