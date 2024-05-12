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
ld solve(ll n, ll a, ld x, ld y, map<ll, ld> &cache) {
  dbg(n);
  if (cache.contains(n))
    return cache[n];
  if (n == 0)
    return cache[n] = 0;

  ld res = x + solve(n / a, a, x, y, cache);

  ld cand = 0;
  for (ll i = 2; i <= 6; i++) {
    cand += solve(n / i, a, x, y, cache);
  }

  return cache[n] = min(res, (ld)6 / (ld)5 * y + (ld)1 / (ld)5 * cand);
}
int main() {
  ll n, a, x, y;
  cin >> n >> a >> x >> y;
  map<ll, ld> cache;
  cout << fixed << setprecision(12) << solve(n, a, x, y, cache) << endl;
  return 0;
}
