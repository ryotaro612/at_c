#include <bits/stdc++.h>
#include <limits>
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
ld rec(int mask, int d, vector<ld> &wv, ld avg, vector<vector<ld>> &dp) {
  if (dp[mask][d] >= 0) {
    return dp[mask][d];
  }
  if (d == 1) {
    ld res = 0;
    for (int i = 0; (1 << i) <= mask; i++) {
      if ((1 << i) & mask)
        res += wv[i];
    }
    return dp[mask][d] = (res - avg) * (res - avg);
  }

  ld res = numeric_limits<ld>::max();
  int next_mask = mask;
  while (true) {
    res = min(res, rec(next_mask, 1, wv, avg, dp) +
                       rec(next_mask ^ mask, d - 1, wv, avg, dp));
    if (next_mask == 0)
      break;
    next_mask = (next_mask - 1) & mask;
  }
  return dp[mask][d] = res;
}
int main() {
  int n, d;
  cin >> n >> d;
  vector<ld> wv(n);
  ld avg = 0;
  rep(i, n) {
    cin >> wv[i];
    avg += wv[i];
  }
  avg /= (ld)d;
  vector<vector<ld>> dp(1 << n, vector<ld>(d + 1, -1));
  rep(mask, 1 << n) {
    ld sum = 0;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i))
        sum += wv[i];
    }
    dp[mask][1] = (sum - avg) * (sum - avg);

    for (int i = 2; i <= d; i++) {
      int next_mask = mask;
      ld cand = numeric_limits<ld>::max();
      while (true) {
        cand = min(cand, dp[next_mask][1] + dp[mask ^ next_mask][i - 1]);
        if (next_mask == 0)
          break;
        next_mask = (next_mask - 1) & mask;
      }
      dp[mask][i] = cand;
    }
  }
  cout << fixed << setprecision(12) << dp[(1 << n) - 1][d] / (ld)d << endl;
  // ld res = rec((1 << n) - 1, d, wv, avg, dp) / (ld)d;
  // dbg(dp);
  // cout << fixed << setprecision(12) << res << endl;
  return 0;
}
