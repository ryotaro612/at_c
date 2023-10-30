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
const ll MOD = 998244353ll;

pair<ll, ll> ext_gcd(ll a, ll b) {
  if (b == 0)
    return {1, 0};
  auto [x, y] = ext_gcd(b, a % b);
  return {y, x - a / b * y};
}
ll mod_inv(ll a) {
  auto [x, _] = ext_gcd(a, MOD);
  return (x % MOD + MOD) % MOD;
}
ll mod_div(ll a, ll b) { return a * mod_inv(b) % MOD; }
int main() {
  int n;
  cin >> n;
  vector<ll> av(n);
  rep(i, n) {
    cin >> av[i];
    av[i] %= MOD;
  }

  ll acc = 1ll, res = 0;
  rep(i, av.size()) {
    res += mod_div(acc, n) * av[i] % MOD;
    res %= MOD;
    acc += mod_div(acc, n);
    acc %= MOD;
  }
  cout << res << endl;
  return 0;
}
