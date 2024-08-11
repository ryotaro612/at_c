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
  // 30
  cin >> n;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  ll res = 0;
  for (ll i = 0; i < 30; i++) {
    ll prev = res;
    vector<ll> bits(n, 0);
    rep(j, n) {
      if (av[j] & (1ll << i))
        bits[j]++;
    }
    dbg(i, bits);
    ll n_odd = 0;
    if (bits[n - 1] ^ bits[n - 2]) {
      n_odd++;
      res += 1ll << i;
    }
    dbg(n - 2, n_odd);
    for (ll j = n - 3; j >= 0; j--) {
      if (bits[j]) {
		n_odd = (n - j - 2ll) - n_odd;
      } else {
      }
      if (bits[j] ^ bits[j + 1])
        n_odd++;
      res += n_odd * (1ll << i);
      dbg(j, n_odd);
    }
    dbg(i, res - prev);
  }
  cout << res << endl;
  return 0;
}
