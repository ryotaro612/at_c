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

  ll res = n * n;
  set<pair<ll, ll>> ng;
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
	a--;
	b--;
    vector<pair<ll, ll>> toru = {{a + 2, b + 1}, {a + 1, b + 2}, {a - 1, b + 2},
                                 {a - 2, b + 1}, {a - 2, b - 1}, {a - 1, b - 2},
                                 {a + 1, b - 2}, {a + 2, b - 1}};

	
    for (auto [x, y] : toru) {
      if (0 <= x && x < n && 0 <= y && y < n) {
        ng.insert({x, y});
      }
    }
	ng.insert({a, b});
  }
  cout << res - (ll)ng.size() << endl;

  return 0;
}
