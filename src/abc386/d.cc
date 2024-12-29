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
  vector<tuple<ll, ll, ll>> tv(m);
  rep(i, m) {
    ll x, y, z;
	char c;
    cin >> x >> y >> c;
	if(c == 'W') z = 0;
	else
	  z = 1;
    tv[i] = {y, x, z};
  }
  sort(tv.begin(), tv.end());
  ll white_c = 10000000000000000ll;
  rep(i, m) {
	auto [y, x, c] = tv[i];
	if(c == 1){
	  if(white_c <= x){
		cout << "No\n";
		return 0;
	  } 
	} else {
	  white_c = min(white_c, x);
	}
  }

  cout << "Yes\n";
  return 0;
}
