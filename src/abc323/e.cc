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

ll const MOD = 998244353ll;
pair<ll, ll> extgcd(ll a, ll b) {
  if (b == 0)
    return {1, 0};
  auto [x, y] = extgcd(b, a % b);
  return {y, x - (a / b) * y};
}
ll modinv(ll v) {
  auto [x, _] = extgcd(v, MOD);
  return (x % MOD + MOD) % MOD;
}
ll moddiv(ll a, ll b) { return a * modinv(b) % MOD; }

int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> tv(n);
  rep(i, n) cin >> tv[i];
  vector<ll> start(x + 1, 0);
  start[0] = 1;
  ll prob = modinv(n);
  ll res = 0;
  dbg(prob);
  rep(i, x + 1) {
    rep(j, n) {
      if (i + tv[j] <= x) {
        start[i + tv[j]] += start[i] * prob % MOD;
        start[i + tv[j]] %= MOD;
      } else {
	if(j == 0) {
	  res += start[i] * prob % MOD;
	  res %= MOD;
	}
      }
    }
  }
  dbg(start);
  cout << res << endl;
  return 0;
}
