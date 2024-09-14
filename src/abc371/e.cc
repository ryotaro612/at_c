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
  cin >> n;
  vector<int> av(n);
  rep(i, n) { cin >> av[i]; }
  map<int, set<int>> pv;
  rep(i, n) { pv[av[i]].insert(i); }
  ll res = 0;
  for (auto [x, st] : pv) {
    vector<ll> pos;
	dbg(x, st);
    for (auto e : st)
      pos.push_back(e);
    ll temp = 0;
    rep(i, pos.size()) {
      if (i == 0) {
        temp += pos[i] * (pos[i] + 1ll) / 2ll;
      } else {
        ll diff = pos[i] - pos[i - 1] - 1ll;
		dbg(diff);
        temp += diff * (diff + 1ll) / 2ll;
      }
      if (i == (int)pos.size() - 1) {
        ll diff = n - 1 - pos[i];
		dbg(2, diff);
        temp += diff * (diff + 1ll) / 2ll;
      }
	  dbg(i, temp);
    }
	dbg(temp);
	dbg(n * (n + 1ll) / 2ll - temp);
    res += n * (n + 1ll) / 2ll - temp;
  }
  cout << res << endl;
  return 0;
}
