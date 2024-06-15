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
  int n, m;
  cin >> n >> m;
  vector<ll> av(n), bv(m);
  rep(i, n) cin >> av[i];
  rep(i, m) cin >> bv[i];

  multiset<ll> as(begin(av), end(av));
  ll res = 0;
  sort(begin(bv), end(bv));
  for (int i = m - 1; i >= 0; i--) {
	auto iter = as.lower_bound(bv[i]);
	if(iter != as.end()) {
	  res += *iter;
	  as.erase(iter);
	} else {
	  cout << -1 << endl;
	  return 0;
	}
  }
  cout << res << endl;
  return 0;
}
