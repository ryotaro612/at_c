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

ld my_pow(ld x, ll n) {
  ld res = 1ll;
  while (n) {
    if (n & 1)
      res *= x;
    n >>= 1;
    x *= x;
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  vector<ld> pv(n);
  rep(i, n) cin >> pv[i];
  vector<ld> denom_sum(n + 1, 0);
  denom_sum[1] = 1;
  for (int i = 2; i <= n; i++) {
    denom_sum[i] =
        denom_sum[i - 1] + (denom_sum[i - 1] - denom_sum[i - 2]) * (ld)0.9;
  }
  dbg(denom_sum);
  ld res = -10000000000000;
  dbg(res);

  vector<vector<ld>> dp_n(n, vector<ld>(n + 1, -10000000000000ll));

  rep(i, n) {
    dp_n[i][1] = pv[i];
    if(i)
      dp_n[i][1] = max(dp_n[i][1], dp_n[i-1][1]);


    res = max(res, pv[i] - (ld)1200);
    for (int k = 2; k <= i + 1; k++) {
      dp_n[i][k] = (ld)0.9 * dp_n[i - 1][k - 1] + pv[i];
      dbg(i, k, dp_n[i][k]);
      if (k <= i)
        dp_n[i][k] = max(dp_n[i][k], dp_n[i - 1][k]);
      
      res = max(res, dp_n[i][k] / denom_sum[k] - (ld)1200 / sqrt(k));
    }
  }

  cout << fixed << setprecision(12) << res << endl;
  return 0;
}
