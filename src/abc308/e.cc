#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
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

// #ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<vector<vector<ll>>> dp(n + 1,
                                vector<vector<ll>>(2, vector<ll>(8, 0ll)));
  vector<int> av(n);
  rep(i, n) cin >> av[i];
  string s;
  cin >> s;
  ll res = 0ll;
  rep(i, n) {
    rep(j, 2) {
      rep(k, 8) { dp[i + 1][j][k] += dp[i][j][k]; }
    }
    if (s[i] == 'M') {
      dp[i + 1][0][1 << av[i]] += 1ll;
    } else if (s[i] == 'E') {
      rep(j, 8) { dp[i + 1][1][j | (1 << av[i])] += dp[i][0][j]; }
    } else {
      rep(j, 8) {
        int k = j | (1 << av[i]);
        if (dp[i][1][j]) {
          debug(dp[i][1][j], k);
        }

        if (k == 1 || k == 5)
          res += dp[i][1][j];
        else if (k == 3)
          res += dp[i][1][j] * 2ll;
        else if (k == 7)
          res += dp[i][1][j] * 3ll;
      }
    }
  }
  rep(i, n) {
    debug(i + 1);
    debug(dp[i + 1]);
  }

  cout << res << endl;
  return 0;
}
// #endif
