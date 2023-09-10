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
  ll x, y;
  cin >> n >> x >> y;
  vector<int> pv(n - 1);
  vector<ll> tv(n - 1);
  rep(i, n - 1) cin >> pv[i] >> tv[i];
  vector<ll> dp(840, y);

  for (int i = n - 2; i >= 0; i--) {
    vector<ll> next_dp(840, 0);
    rep(j, 840) {
      for (ll k = 0; k <= 9; k++) {
        if ((j + k) % pv[i] == 0) {
          next_dp[j] = k + tv[i] + dp[(j + k + tv[i]) % 840];
          break;
        }
      }
    }
    dp = next_dp;
    dbg(dp[13], dp[15], dp[19], dp[24], dp[30], dp[31], dp[34]);
  }

  int q;
  cin >> q;
  rep(_, q) {
    ll qi;
    cin >> qi;
    cout << qi + x + dp[(qi + x) % 840] << endl;
  }
  return 0;
}
