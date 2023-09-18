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
  int n, m, p, q, r;
  cin >> n >> m >> p >> q >> r;
  vector<int> xv(r), yv(r);
  vector<ll> zv(r);
  rep(i, r) {
    cin >> xv[i] >> yv[i] >> zv[i];
    xv[i]--;
    yv[i]--;
  }
  ll res = 0ll;
  rep(girls, 1 << n) {
    bitset<18> bs(girls);
    if((int)bs.count() != p)
      continue;
    vector<ll> men(m, 0);
    rep(i, r) {
      if ((1 << xv[i]) & girls) {
        men[yv[i]] += zv[i];
      }
    }
    sort(begin(men), end(men), greater<ll>());
    ll temp = 0ll;
    rep(i, q) temp += men[i];
    res = max(res, temp);
  }
  cout << res << endl;
  return 0;
}
