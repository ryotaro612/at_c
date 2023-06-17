#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <algorithm>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template <typename T> ostream &operator<<(ostream &os, vector<T> &v) {
  cout << "[";
  string s[2] = {", ", "]"};
  rep(i, v.size()) { cout << v[i] << s[i == int(v.size()) - 1]; }
  return os;
}
void debug_() { cout << endl; }

template <typename Head, typename... Tail> void debug_(Head H, Tail... T) {
  cout << H << " ";
  debug_(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...) debug_(__VA_ARGS__)
#else
#define debug(...)
#endif

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
  dp[0][1] = -10000000000000ll;
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    if (x) {
      dp[i + 1][0] = dp[i][0];
      dp[i + 1][1] = dp[i][1];
      dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + y);
    } else {
      dp[i + 1][0] = dp[i][0];
      dp[i + 1][1] = dp[i][1];

      dp[i + 1][0] = max(dp[i + 1][0], max(dp[i][0], dp[i][1]) + y);
    }
  }
  rep(i, n) { debug(i + 1, dp[i + 1]); }
  cout << max(dp[n][0], dp[n][1]) << endl;
  return 0;
}
#endif
