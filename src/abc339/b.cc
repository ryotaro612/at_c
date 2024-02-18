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
  int h, w, n;
  cin >> h >> w >> n;
  vector<string> grid(h, string(w, '.'));
  int r = 0, c = 0;
  vector<pair<int, int>> d = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  int cur = 0;
  rep(_, n) {
    if (grid[r][c] == '.') {
      grid[r][c] = '#';
      cur += 1;
      cur %= 4;
    } else {
      grid[r][c] = '.';
      cur -= 1;
      cur += 4;
      cur %= 4;
    }

    r += d[cur].first + h;
    r %= h;
    c += d[cur].second + w;
    c %= w;
  }
  rep(i, h) {
    cout << grid[i] << endl;
  }
  return 0;
}
