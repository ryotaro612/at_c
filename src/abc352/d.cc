#include <algorithm>
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
  int n, k;
  cin >> n >> k;

  vector<ll> pv(n);
  map<int, int> pos_map;
  rep(i, n) {
    cin >> pv[i];
    pv[i]--;
    pos_map[pv[i]] = i;
  }
  // ポジションの位置
  set<ll> order;

  rep(i, k) { order.insert(pos_map[i]); }
  ll res = *order.rbegin() - *order.begin();
  dbg(*order.rbegin(), *order.begin());
  for (int i = 0; i + k < n; i++) {
    order.erase(pos_map[i]);
    order.insert(pos_map[i + k]);
    // dbg(i, *order.rbegin(), *order.begin());
    res = min(res, *order.rbegin() - *order.begin());
  }

  cout << res << endl;

  return 0;
}
