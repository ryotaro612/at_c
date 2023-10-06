#include <bits/stdc++.h>
#include <iomanip>
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
/**
   金額の期待値を返す。
 */
ld solve(int point, vector<int> &cv, vector<vector<int>> &sv, vector<ld> &dp) {
  if (point >= (int)dp.size() - 1)
    return dp.back() = 0;
  if(dp[point] >=0)
    return dp[point];

  ld res = 10000000000000ll;

  rep(i, cv.size()) {
    int n_positive = 0;
    for (auto &s : sv[i]) {
      if (s)
        n_positive++;
    }
    ld cost = (ld)cv[i] * (ld)sv[i].size() / (ld)n_positive;
    ld acc = 0;
    rep(j, sv[i].size()) {
      if (sv[i][j])
        acc += solve(point + sv[i][j], cv, sv, dp) / (ld)n_positive;
    }
    res = min(res, cost + acc);
  }
  return dp[point] = res;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> cv(n);
  vector<vector<int>> sv(n);
  rep(i, n) {
    cin >> cv[i];
    int p;
    cin >> p;
    sv[i].resize(p);
    rep(j, p) cin >> sv[i][j];
  }
  vector<ld> dp(m + 1, -1);
  cout << fixed << setprecision(12) << solve(0, cv, sv, dp) << endl;

  return 0;
}
