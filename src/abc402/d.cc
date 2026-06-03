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
pair<int, int> norm(int a, int b, int n) {
  if (a <= n - b) {
    return {0, b + a};
  }
  return {0, a - (n - b)};
}
int main() {
  ll n, m;
  cin >> n >> m;
  map<pair<int, int>, ll> mp;
  vector<ll> av(m), bv(m);
  rep(i, m) {
    cin >> av[i];
    cin >> bv[i];
    mp[norm(--av[i], --bv[i], n)]++;
  }
  ll res = 0;
  rep(i, m) { res += m - mp[norm(av[i], bv[i], n)]; }

  cout << res / 2ll << endl;
  return 0;
}
