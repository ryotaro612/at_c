#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
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

  int n;
  cin >> n;
  vector<ll> wv(n), hv(n), bv(n);
  ll total_weight = 0;
  rep(i, n) {
    cin >> wv[i] >> hv[i] >> bv[i];
    total_weight += wv[i];
  }
  vector<ll> dp = {0};
  ll acc = 0;
  rep(i, n) {
    vector<ll> new_dp((ll)dp.size() + wv[i], -1000000000000000ll);
    acc += wv[i];
    rep(hw, dp.size()) {
      ll new_hw = hw + wv[i];
      if (new_hw <= total_weight / 2ll) {
        new_dp[new_hw] = max(new_dp[new_hw], dp[hw] + hv[i]);
      }
      new_dp[hw] = max(new_dp[hw], dp[hw] + bv[i]);
    }
    dp = new_dp;
  }

  ll res = 0;
  for (int i = 0; i <= total_weight / 2ll; i++) {
    res = max(res, dp[i]);

    dbg(i, dp[i]);
  }
  cout << res << endl;
  return 0;
}
