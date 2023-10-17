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
  int n;
  cin >> n;
  map<ll, ll> slimes;
  ll max_size = 0;
  rep(i, n) {
    ll s, c;
    cin >> s >> c;
    slimes[s] = c;
    max_size = max(max_size, s);
  }

  ll res = 0;
  while (slimes.size()) {
    ll s = begin(slimes)->first;
    ll c = begin(slimes)->second;
    if (s * 2ll <= max_size) {
      if (c % 2)
        res++;
      slimes[s * 2ll] += c / 2ll;
    } else {
      while(c) {
	if(c % 2ll) {
	  res++;
	}
	c/= 2ll;
      }
    }
    slimes.erase(begin(slimes));
  }
  cout << res << endl;
  return 0;
}
