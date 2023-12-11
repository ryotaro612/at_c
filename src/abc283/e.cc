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

vector<int> get_isolation(vector<int> &prev, vector<int> &cur) {
  int w = prev.size();
  vector<int> res(w, 0);
  rep(c, w) {
    if (!(prev[c] == cur[c] || (c > 0 && cur[c - 1] == cur[c]) ||
          (c < w - 1 && cur[c] == cur[c + 1]))) {
      res[c] = 1;
    }
  }
  return res;
}
bool is_mask_ok(vector<int> isolation, vector<int> &prev, vector<int> &cur) {
  bool ok = true;
  int w = isolation.size();
  rep(c, w) {
    if (isolation[c] == 1 && cur[c] != prev[c])
      ok = false;
  }
  return ok;
}
int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> am(h + 2, vector<int>(w, 0)),
      flip_am(h + 2, vector<int>(w, 0));
  rep(r, h) {
    rep(c, w) { cin >> am[r + 1][c]; }
  }
  rep(c, w) {
    am[0][c] = 100;
    am[h + 1][c] = 100;
  }
  rep(r, h + 2) {
    rep(c, w) { flip_am[r][c] = 1 - am[r][c]; }
  }

  const int inf = 100000;
  vector<vector<vector<int>>> dp(h + 2,
                                 vector<vector<int>>(2, vector<int>(2, inf)));
  dp[0][0][0] = dp[0][1][0] = 0;

  dp[1][0][0] = 0;
  dp[1][0][1] = 1;
  for (int r = 2; r < h + 2; r++) {
    dbg(r);
    // 00
    bool ok = is_mask_ok(get_isolation(am[r - 2], am[r - 1]), am[r - 1], am[r]);
    dbg(ok, get_isolation(am[r - 2], am[r - 1]));
    if (ok) {
      dp[r][0][0] = dp[r - 1][0][0];
    }
    ok = is_mask_ok(get_isolation(flip_am[r - 2], am[r - 1]), am[r - 1], am[r]);
    dbg(ok);
    if (ok) {
      dp[r][0][0] = min(dp[r][0][0], dp[r - 1][1][0]);
    }
    // 01
    ok = is_mask_ok(get_isolation(am[r - 2], am[r - 1]), am[r - 1], flip_am[r]);
    if (ok) {
      dp[r][0][1] = dp[r - 1][0][0] + 1;
    }
    ok = is_mask_ok(get_isolation(flip_am[r - 2], am[r - 1]), am[r - 1],
                    flip_am[r]);
    if (ok) {
      dp[r][0][1] = min(dp[r][0][1], dp[r - 1][1][0] + 1);
    }
    // 10
    ok = is_mask_ok(get_isolation(am[r - 2], flip_am[r - 1]), flip_am[r - 1],
                    am[r]);
    if (ok) {
      dp[r][1][0] = dp[r - 1][0][1];
    }
    ok = is_mask_ok(get_isolation(flip_am[r - 2], flip_am[r - 1]),
                    flip_am[r - 1], am[r]);
    if (ok) {
      dp[r][1][0] = min(dp[r][1][0], dp[r - 1][1][1]);
    }
    // 11
    ok = is_mask_ok(get_isolation(am[r - 2], flip_am[r - 1]), flip_am[r - 1],
                    flip_am[r]);
    if (ok) {
      dp[r][1][1] = dp[r - 1][0][1] + 1;
    }
    ok = is_mask_ok(get_isolation(flip_am[r - 2], flip_am[r - 1]),
                    flip_am[r - 1], flip_am[r]);
    if (ok) {
      dp[r][1][1] = min(dp[r][1][1], dp[r - 1][1][1] + 1);
    }
  }
  rep(i, h + 2) { dbg(dp[i]); }
  int res = min(dp[h + 1][0][0], dp[h + 1][1][0]);
  if (res < inf)
    cout << res << endl;
  else
    cout << -1 << endl;

  return 0;
}
