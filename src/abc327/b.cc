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
map<ll, ll> prime_factorization(ll num) {
  map<ll, ll> mp;
  for (ll i = 2ll; i * i <= num; i++) {
    while (num % i == 0) {
      mp[i]++;
      num /= i;
    }
  }
  if (num != 1ll)
    mp[num]++;
  return mp;
}

ll my_pow(ll x, ll n) {
  ll res = 1ll;
  while (n) {
    if (n & 1)
      res *= x;
    n >>= 1;
    x *= x;
  }
  return res;
}
int main() {
  ll b;
  cin >> b;
  for (int i = 1; i <= 16; i++) {
    if (my_pow(i, i) == b) {
      cout << i << endl;
      return 0;
    }
  }
  cout << "-1\n";
  return 0;
}
