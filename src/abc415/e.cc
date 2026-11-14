#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numbers>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll h, w;
  cin >> h >> w;
  vector<vector<ll>> grid(h, vector<ll>(w));
  rep(r, h) {
    rep(c, w) { cin >> grid[r][c]; }
  }

  vector<ll> pv(h + w - 1);

  rep(i, h + w - 1) { cin >> pv[i]; }

  ll lb = -1;
  ll ub = 1000000000ll * (h + w - 1ll) + 1ll;

  while (ub - lb > 1ll) {
    ll mid = (ub + lb) / 2ll;
    vector<vector<ll>> dp(h, vector<ll>(w, -100000000000000ll));
    dp[0][0] = mid + grid[0][0] - pv[0];
    for (int tr = 0, tc = 0; tr < h && tc < w; tr++, tc++) {
      if (dp[0][0] < 0)
        break;
      for (int r = tr; r < h; r++) {
        dbg(r, tc);
        if (r && dp[r - 1][tc] >= 0) {
          dp[r][tc] = max(dp[r][tc], dp[r - 1][tc] + grid[r][tc] - pv[r + tc]);
        }
        if (tc && dp[r][tc - 1] >= 0) {
          dp[r][tc] = max(dp[r][tc], dp[r][tc - 1] + grid[r][tc] - pv[r + tc]);
        }
      }
      for (int c = tc; c < w; c++) {
        dbg(tr, c);
        if (tr && dp[tr - 1][c] >= 0) {
          dp[tr][c] = max(dp[tr][c], dp[tr - 1][c] + grid[tr][c] - pv[tr + c]);
        }
        if (c && dp[tr][c - 1] >= 0) {
          dp[tr][c] = max(dp[tr][c], dp[tr][c - 1] + grid[tr][c] - pv[tr + c]);
        }
      }
    }
    dbg(mid);
    dbg(dp);
    if (dp[h - 1][w - 1] >= 0) {
      ub = mid;
    } else {
      lb = mid;
    }
  }
  cout << ub << endl;
}
