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
  string s, t;
  cin >> n >> m >> s >> t;

  bool is_prefix = true, is_suffix = true;
  rep(i, s.size()) {
    if (s[i] != t[i])
      is_prefix = false;

    if (s[s.size() - 1 - i] != t[t.size() - 1 - i])
      is_suffix = false;
  }
  int res;
  if (is_prefix) {
    if (is_suffix)
      res = 0;
    else
      res = 1;
  } else {
    if (is_suffix)
      res = 2;
    else
      res = 3;
  }
  cout << res << endl;

  return 0;
}
