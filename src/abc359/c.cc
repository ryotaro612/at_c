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
ll x_idx(ll x, ll y) {
  if (y % 2ll) {
    return (x + 1ll) / 2ll;
  }
  return x / 2ll;
}

ll solve(ll sx, ll sy, ll tx, ll ty) {
  if (sx == tx)
    return abs(sy - ty);
  if (sy == ty) {
    return abs(x_idx(sx, sy) - x_idx(tx, ty));
  }
  ll diff;
  if (abs(sx - tx) <= abs(ty - sy))
    diff = abs(sx - tx);
  else
    diff = abs(ty - sy);

  if (sx < tx) {
    if (sy < ty) {
      return diff + solve(sx + diff, sy + diff, tx, ty);
    } else {
      return diff + solve(sx + diff, sy - diff, tx, ty);
    }
  } else {
    if (sy < ty) {
      return diff + solve(sx - diff, sy + diff, tx, ty);
    } else {
      return diff + solve(sx - diff, sy - diff, tx, ty);
    }
  }
}
int main() {
  ll sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  cout << solve(sx, sy, tx, ty) << endl;
  return 0;
}
