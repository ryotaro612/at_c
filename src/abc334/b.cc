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
  ll a0, m0, l0, r0;
  cin >> a0 >> m0 >> l0 >> r0;
  __int128 a = a0, m = m0, l = l0, r = r0;
  l -= a;
  r -= a;
  ll res;
  if (0 <= l) {
    l += m - 1ll;
    res = r / m - l / m + 1ll;
  } else if (r <= 0) {
    ll temp_l = -r;
    r = -l;
    l = temp_l;
    l += m - 1ll;
    res = r / m - l / m + 1ll;
  } else {
    res = r / m - l / m + 1ll;
  }

  cout << res << endl;

  return 0;
}
