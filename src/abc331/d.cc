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

ll count(ll r, ll c, vector<vector<ll>> &grid) {
  ll n = grid.size();
  ll m_r = r % n;
  ll m_c = c % n;
  ll res = grid[m_r][m_c];
  ll r_rep = r / n;
  ll c_rep = c / n;
  res += r_rep * c_rep * grid[n - 1][n - 1];
  res += grid[n - 1][m_c] * r_rep;
  res += grid[m_r][n - 1] * c_rep;
  return res;
}
int main() {
  ll n, q;
  cin >> n >> q;
  vector<vector<ll>> grid(n, vector<ll>(n, 0));
  rep(r, n) {
    rep(c, n) {
      char color;
      cin >> color;
      if (color == 'B') {
        grid[r][c] = 1;
      }
    }
  }
  rep(r, n) {
    rep(c, n) {
      if (r)
        grid[r][c] += grid[r - 1][c];
      if (c)
        grid[r][c] += grid[r][c - 1];
      if (r && c)
        grid[r][c] -= grid[r - 1][c - 1];
    }
  }
  dbg(grid);
  rep(_, q) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (!(a <= c && b <= d)) {
      cout << 0 << endl;
      continue;
    }
    ll res = count(c, d, grid);
    if (a)
      res -= count(a - 1ll, d, grid);
    if (b)
      res -= count(c, b - 1ll, grid);
    if (a && b)
      res += count(a - 1ll, b - 1ll, grid);
    cout << res << endl;
  }

  return 0;
}
