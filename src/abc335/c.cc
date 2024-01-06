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
  int n, q;
  cin >> n >> q;
  vector<pair<int, int>> pos;
  rep(i, n) { pos.push_back({i + 1, 0}); }
  reverse(begin(pos), end(pos));
  int x = 1, y = 0;
  map<char, pair<int, int>> delta;
  delta['R'] = {1, 0};
  delta['L'] = {-1, 0};
  delta['U'] = {0, 1};
  delta['D'] = {0, -1};
  rep(i, q) {
    int a;
    cin >> a;
    if (a == 1) {
      char c;
      cin >> c;
      x += delta[c].first;
      y += delta[c].second;
      pos.push_back({x, y});
    } else {
      int p;
      cin >> p;
      auto b = pos[pos.size() - p];
      cout << b.first << " " << b.second << endl;
    }
  }
  return 0;
}
