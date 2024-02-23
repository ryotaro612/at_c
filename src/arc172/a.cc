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
  ll h, w, n;
  cin >> h >> w >> n;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  ll area = h * w;
  rep(i, n) { area -= my_pow(2ll, av[i]) * my_pow(2, av[i]); }
  if (area < 0) {
    cout << "No\n";
    return 0;
  }
  sort(begin(av), end(av), greater<ll>());
  multiset<pair<ll, ll>> recs;
  recs.insert({min(h, w), max(h, w)});
  for (auto a : av) {
    ll len = my_pow(2, a);
    auto iter = recs.lower_bound({len, len});
    if (iter == recs.end()) {
      cout << "No\n";
      return 0;
    }
    ll height = iter->first;
    ll width = iter->second;
    recs.erase(iter);
    if (len < height) {
      recs.insert({min(len, width - len), max(len, width - len)});
      recs.insert({height - len, width});
    } else {
      recs.insert({min(len, width - len), max(len, width - len)});
    }
    dbg(width, height, len, a);
    dbg(recs);
  }
  cout << "Yes\n";
  return 0;
}
