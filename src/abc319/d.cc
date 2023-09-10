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
  vector<ll> lv(n);
  rep(i, n) cin >> lv[i];
  ll lb = *max_element(begin(lv), end(lv)) - 1ll, ub = 1000000000000000ll;

  while (ub - lb > 1ll) {
    ll mid = (lb + ub) / 2ll;
    ll buf = mid, n_lines = 0;
    rep(i, n) {
      ll l = lv[i];
      if (buf + 1ll + l <= mid)
        buf += 1ll + l;
      else {
        n_lines++;
        buf = l;
      }
    }
    if (m < n_lines)
      lb = mid;
    else
      ub = mid;
  }
  cout << ub << endl;
  return 0;
}
