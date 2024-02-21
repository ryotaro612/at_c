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
int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  ll ub = numeric_limits<ll>::max();
  ll lb = 0;
  ll g = lcm(n, m);
  while (ub - lb > 1ll) {
    ll mid = (ub + lb) / 2ll;
    ll cand = max(mid / n * n, mid / m * m);
    if (cand % n == 0 && cand % m == 0)
      cand -= min(n, m);
    ll count = -cand / g * 2ll + cand / n + cand / m;
    if(count == k) {
      cout << cand << endl;
      return 0;
    }
    if (k < count)
      ub = mid;
    else
      lb = mid;

  }
  cout << lb << endl;
  return 0;
}
