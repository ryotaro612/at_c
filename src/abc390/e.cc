#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
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

vector<ll> sub(ll x, vector<ll> &av, vector<ll> &cv) {
  // dp[x] = y カロリーx以下でとれるビタミンの最大値
  vector<ll> dp(x + 1, 0);
  rep(i, av.size()) {
    vector<ll> next_dp = vector<ll>(dp);
    rep(k, x + 1) {
      if (k + cv[i] <= x) {
        next_dp[k + cv[i]] = max(next_dp[k + cv[i]], dp[k] + av[i]);
      }
    }
    dp = next_dp;
  }
  return dp;
}
int main() {
  ll n, x;
  cin >> n >> x;
  vector<vector<ll>> av(3), cv(3);
  rep(i, n) {
    ll v, a, c;
    cin >> v >> a >> c;
    --v;
    av[v].push_back(a);
    cv[v].push_back(c);
  }
  vector<ll> dp0 = sub(x, av[0], cv[0]);
  vector<ll> dp1 = sub(x, av[1], cv[1]);
  vector<ll> dp2 = sub(x, av[2], cv[2]);
  ll res = 0;
  for (int i = 0; i <= x; i++) {
    for (int j = 0; j + i <= x; j++) {
      res = max(res, min(dp0[x - i - j], min(dp1[i], dp2[j])));
    }
  }

  cout << res << endl;
  return 0;
}
