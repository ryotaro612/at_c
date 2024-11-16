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
  vector<pair<ll, ll>> rl(n);
  rep(i, n) {
    ll l, r;
    cin >> l >> r;
    rl[i] = {r, l};
  }
  sort(begin(rl), end(rl));
  int j = 0;
  ll res = 0;
  for (ll i = 1; i <= m; i++) {

	while(j < (int) rl.size() && rl[j].second < i) {
	  j++;
	}
	if(j < (int)rl.size()) {
	  res += rl[j].first - i;
	}else {
	  res += m - i + 1ll;
	}
  }
  cout << res << endl;

  return 0;
}
