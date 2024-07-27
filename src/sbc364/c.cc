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
  ll n, x, y;
  cin >> n >> x >> y;
  vector<ll> av(n), bv(n);
  rep(i, n) cin >> av[i];
  rep(i, n) cin >> bv[i];
  vector<pair<ll, ll>> ab(n);
  rep(i, n) { ab[i] = {av[i], bv[i]}; }
  sort(begin(ab), end(ab));
  reverse(begin(ab), end(ab));
  int res = n;
  ll t = 0;
  rep(i, n) {
    t += ab[i].first;
    if (t > x) {
      res = i + 1;
      break;
    }
  }
  vector<pair<ll, ll>> ba(n);
  rep(i, n) {
	ba[i] = {bv[i], av[i]};
  }
  sort(begin(ba), end(ba));
  reverse(begin(ba), end(ba));
  t = 0;
  rep(i, n) {
    t += ba[i].first;
    if (t > y) {
      res = min(i + 1, res);
      break;
    }
  }
  cout << res << endl;
  return 0;
}
