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
  ll n, m;
  cin >> n >> m;
  vector<ll> xv(m), av(m);

  rep(i, m) {
    cin >> xv[i];
    xv[i]--;
  }
  ll sum = 0;
  rep(i, m) {
    cin >> av[i];
    sum += av[i];
  }
  if (sum != n) {
    cout << -1 << endl;
    return 0;
  }
  vector<pair<ll, ll>> xa(m);
  rep(i, m) { xa[i] = {xv[i], av[i]}; }
  sort(begin(xa), end(xa));

  if (xa[0].first != 0) {
    cout << -1 << endl;
    return 0;
  }
  ll cur = 0;
  ll res = 0;
  rep(i, m) {
    dbg(i);
    if (cur < 0) {
      cout << -1 << endl;
      return 0;
    }
    cur += xa[i].second;
    if (i < m - 1) {
      ll dist = xa[i + 1].first - xa[i].first;
      res += (2ll * cur * dist - dist * dist - dist) / 2ll;
      cur -= dist;
    } else {
      ll dist = (n - 1ll) - xa[i].first;
      res += (2ll * cur * dist - dist * dist - dist) / 2ll;
      cur -= dist;
    }
  }
  if (cur < 0) {
    cout << -1 << endl;
    return 0;
  }
  cout << res << endl;
  return 0;
}
