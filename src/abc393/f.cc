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
int main() {
  int n, q;
  cin >> n >> q;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  vector<tuple<ll, ll, int>> rxv(q);
  rep(i, q) {
    ll r, x;
    cin >> r >> x;
    rxv[i] = {r, x, i};
  }
  sort(begin(rxv), end(rxv));
  vector<ll> dp(n, 1000000000000000000ll);

  int forward = 0;

  vector<ll> res(q);
  dbg(av);
  rep(i, q) {
    auto [r, x, idx] = rxv[i];
    dbg(forward, r, x, idx, dp);
    while (forward < r) {
      auto iter = lower_bound(begin(dp), end(dp), av[forward]);
      if (iter != end(dp)) {
        *iter = av[forward];
      }

      forward++;
    }

    auto iter = upper_bound(begin(dp), end(dp), x);
    res[idx] = iter - begin(dp);
  }
  rep(i, q) cout << res[i] << endl;
  return 0;
}
