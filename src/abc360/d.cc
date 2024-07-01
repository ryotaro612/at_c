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
  ll n, t;
  string s;

  cin >> n >> t >> s;
  vector<ll> xv(n);
  rep(i, n) cin >> xv[i];
  vector<ll> forward, backward;
  rep(i, n) {
    if (s[i] == '1') {
      forward.push_back(xv[i]);
    } else
      backward.push_back(xv[i]);
  }
  sort(begin(forward), end(forward));
  sort(begin(backward), end(backward));
  ll res = 0;
  set<ll> temp;
  int b_left = 0, b_right = 0;
  dbg(forward);
  dbg(backward);
  rep(i, forward.size()) {
	while(b_left < (int)backward.size() && backward[b_left] < forward[i])
	  b_left++;
	b_right = max(b_left, b_right);
	while(b_right < (int)backward.size() && backward[b_right] - t <= forward[i] + t) {
	  b_right++;
	}
	dbg(i, b_left, b_right);
	res += b_right - b_left;
  }
  cout << res << endl;
  return 0;
}
