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
ll solve(ll n, ll a, ll b, ll c, ll d, map<ll, ll> &memo) {
  ll res = 1e18;
  if (memo.contains(n))
    return memo[n];
  // dbg(n);
  if (n == 0)
    return memo[n] = 0;
  if (n == 1)
    return memo[n] = d;
  // if (n == 3) {
  //   res = min(res, 3ll * d);
  //   res = min(res, d + a + d);
  //   res = min(res, d + b);
  //   res = min(res, 3ll * d + c);
  //   return memo[n] = res;
  // }
  // if (n == 4) {
  //   res = min(res, 4ll * d);
  //   res = min(res, 2ll * a + d);
  //   res = min(res, d + solve(3, a, b, c, d, memo));
  //   res = min(res, 2ll * d + c);
  //   return memo[n] = res;
  // }
  // if (n == 5) {
  //   res = min(res, d + c);
  //   res = min(res, 2ll * d + solve(3, a, b, c, d, memo));
  //   res = min(res, d + solve(4, a, b, c, d, memo));
  //   return memo[n] = res;
  // }

  vector<pair<ll, ll>> seq = {{2, a}, {3, b}, {5, c}};
  if (n < res / d)
    res = n * d;
  for (auto [num, cost] : seq) {
    for (ll delta : {1, -1}) {
      for (ll j = 0;; j += delta) {
        if ((n + j) >= 0 && (n + j) % num == 0) {
          res = min(res,
                    abs(j) * d + cost + solve((n + j) / num, a, b, c, d, memo));
          break;
        }
      }
    }
  }
  return memo[n] = res;
}
int main() {
  int t;
  cin >> t;

  rep(_, t) {
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    map<ll, ll> memo;
    cout << solve(n, a, b, c, d, memo) << endl;
    // qdbg(memo);
  }
  return 0;
}
