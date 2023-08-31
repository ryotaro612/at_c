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
  ll n;
  int m;
  cin >> n >> m;
  vector<ll> xv(m);
  rep(i, m) cin >> xv[i];
  sort(begin(xv), end(xv));
  ll ub = 1000000000000000ll, lb = -1;
  while (ub - lb > 1ll) {
    ll mid = (ub + lb) / 2ll;
    dbg(mid);
    ll cur = 0ll;
    for (auto x : xv) {
      dbg(x, cur);
      if (x <= cur) {
        cur = max(cur, x + mid);
        dbg("up", cur);
      } else if (x - cur - 1ll > mid) {
        dbg("ng");
        continue;
      } else {
        ll forward = cur;
        forward = max(mid - 2ll * (x - cur - 1ll) + x, forward);
        forward = max((mid - (x - cur - 1ll)) / 2ll + x, forward);
        cur = forward;
        dbg(forward);
      }
    }
    dbg(cur, mid);
    if (cur < n)
      lb = mid;
    else
      ub = mid;
  }
  cout << ub << endl;

  return 0;
}
