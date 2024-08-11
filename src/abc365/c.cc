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
  ll n, m;
  cin >> n >> m;
  vector<ll> av(n);
  rep(i, n) { cin >> av[i]; }
  // 16
  const ll mx = 10000000000000ll;
  ll ub = mx;
  ll lb = -1;
  while (ub - lb > 1) {
    ll mid = (ub + lb) / 2ll;
    ll acc = 0;
    rep(i, n) { acc += min(av[i], mid); }
    if (acc > m) {
      ub = mid;
    } else
      lb = mid;
  }
  if (lb >= mx -1ll) {
    cout << "infinite";
  } else
    cout << lb;
  cout << endl;
  return 0;
}
