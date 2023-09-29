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

/**
 * [1,n]からなる木でxをルートとして距離kにある子の数
 */
ll count(ll n, ll x, ll k) {
  ll lb = x, ub = x;
  ll i = 0;
  if (k == 0)
    return 1ll;
  for (;;) {
    lb *= 2ll;
    ub = ub * 2ll + 1ll;
    i++;
    if (n < lb)
      return 0;
    else if (k == i)
      return min(ub, n) - lb + 1ll;
  }
}

ll solve(ll n, ll x, ll k) {
  ll res = count(n, x, k);
  ll prev_x = x;
  x /= 2ll;
  k--;
  while (x && k >= 0) {
    res += count(n, x, k) - count(n, prev_x, k - 1ll);
    prev_x = x;
    x /= 2ll;
    k--;
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  rep(_, t) {
    ll n, x, k;
    cin >> n >> x >> k;
    cout << solve(n, x, k) << endl;
  }
  return 0;
}
// 281440616972288
// 140703128616960
