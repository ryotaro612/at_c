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

ll dist2(pair<int, int> a, pair<int, int> b) {
  ll c = (a.first - b.first);
  ll d = (a.second - b.second);
  return c * c + d * d;
}
int main() {
  vector<pair<int, int>> v(3);
  rep(i, 3) {
    int x, y;
    cin >> x >> y;
    v[i] = {x, y};
  }
  if (dist2(v[0], v[1]) + dist2(v[1], v[2]) == dist2(v[0], v[2]) ||
      dist2(v[0], v[1]) + dist2(v[0], v[2]) == dist2(v[1], v[2]) ||
      dist2(v[1], v[2]) + dist2(v[0], v[2]) == dist2(v[1], v[0]))
    cout << "Yes\n";
  else
    cout << "No\n";

  return 0;
}
