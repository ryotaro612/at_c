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
  int w, b;
  cin >> w >> b;
  string tmp = "wbwbwwbwbwbw", s="";
  
  rep(_, 100) { s += tmp; }
  int n_w = 0, n_b = 0;

  for (int i = 0; i < (int)s.size(); i++) {
    dbg(i);
    if (n_w + n_b == w + b) {
      if (s[i - n_w - n_b] == 'w')
        n_w--;
      else
        n_b--;
    }
    if (s[i] == 'w')
      n_w++;
    else
      n_b++;
    if (n_w == w && n_b == b) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";

  return 0;
}
