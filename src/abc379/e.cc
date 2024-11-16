#include <bits/stdc++.h>
#include <string>
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
  string s;
  cin >> n >> s;
  vector<ll> acc(n, 0);
  acc[0] = s[0] - '0';
  for (ll i = 1; i < n; i++) {
    acc[i] = acc[i - 1] + (i + 1ll) * (ll)(s[i] - '0');
  }
  dbg(acc);
  string res;
  ll c = 0;
  rep(i, n) {
    c += acc[n - 1 - i];
    res.push_back((c % 10ll) + '0');
	c /=10ll;
  }
  if(c) {
  string f = to_string(c);
  reverse(begin(f) ,end(f));
  for (auto e: f) {
	res.push_back(e);
  }	
  }


  reverse(begin(res), end(res));
  cout << res << endl;

  return 0;
}
