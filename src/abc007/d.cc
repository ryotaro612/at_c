#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <string>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template <typename T, typename S>
ostream &operator<<(ostream &os, const pair<S, T> a) {
  os << "{" << a.first << ", " << a.second << "}";
  return os;
}
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) {
  os << "{";
  string s[2] = {", ", "}"};
  int size = v.size(), i = 0;
  for (auto e : v) {
    os << e << s[i == (size - 1)];
    i++;
  }
  return os;
}

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  if (v.size() == 0) {
    os << "]";
    return os;
  }
  string s[2] = {", ", "]"};
  rep(i, v.size()) os << v[i] << s[i == int(v.size()) - 1];
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

ll sub(ll n) {
  debug("-->", n);
  string s = to_string(n);
  vector<vector<ll>> dp(s.size() + 1, vector<ll>(2, 0));
  // i番目 0 まだ同じ
  dp[0][0] = 1ll;
  rep(i, s.size()) {
    ll c = s[i] - '0';
    if (c == 4 || c == 9) {
      dp[i + 1][0] = 0;
      dp[i + 1][1] = dp[i][1] * 8ll;
      if (c == 4)
        dp[i + 1][1] += dp[i][0] * 4ll;
      else
        dp[i + 1][1] += dp[i][0] * 8ll;
    } else {
      dp[i + 1][0] = dp[i][0];
      dp[i + 1][1] = dp[i][1] * 8ll;
      if (c < 4)
        dp[i + 1][1] += dp[i][0] * c;
      else // c < 9
        dp[i + 1][1] += dp[i][0] * (c - 1ll);
    }
  }
  debug(dp[s.size()][0]);
  debug(dp[s.size()][1]);
  return n - dp[s.size()][0] - dp[s.size()][1];
}

// g++ -fdiagnostics-color=always -g -O0 --std=c++17 -Wall
// -fsanitize=undefined,address
int main() {
  ll a, b;
  cin >> a >> b;
  cout << sub(b) - sub(a - 1) << endl;
  return 0;
}
